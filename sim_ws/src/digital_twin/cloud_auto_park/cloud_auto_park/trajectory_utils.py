from dataclasses import dataclass
import matplotlib.pyplot as plt
import matplotlib
import math
import numpy as np
from scipy.interpolate import CubicSpline
from scipy import interpolate
from typing import List
from geometry_helpers import OrientedBoundingBox, get_exact_distance_or_overlap
from scipy.optimize import minimize
from copy import deepcopy

@dataclass
class VehiclePose:
    x_m: float = 0.0
    y_m: float = 0.0
    theta_rad: float = 0.0
    
@dataclass
class Trajectory:
    path: np.ndarray
    headings: np.ndarray
    curvatures: np.ndarray
    control_points: np.ndarray
    target_obb: OrientedBoundingBox
    
def xy_to_plot(x, y): return -y, x

def get_rot_mat(theta_rad):
    
    return np.array([
        [np.cos(theta_rad), np.sin(theta_rad)],
        [-np.sin(theta_rad), np.cos(theta_rad)]
    ])

def cubic_bezier(p0, p1, p2, p3, num_points=100):
    t = np.linspace(0, 1, num_points).reshape(-1, 1)
    # Bernstein basis polynomials
    path = (1-t)**3 * p0 + 3*(1-t)**2 * t * p1 + 3*(1-t) * t**2 * p2 + t**3 * p3
    return path

def get_path_length(path):
    x, y = path[0], path[1]
    x_diffs = np.diff(x)
    y_diffs = np.diff(y)
    diffs = np.sqrt(np.square(x_diffs) + np.square(y_diffs))
    cumu_dist = np.cumsum(diffs)
    return cumu_dist[-1]

def cubic_spline(control_points, speed_mps=1.0, sample_rate_hz=25):
    tck,u = interpolate.splprep([control_points[:,0], control_points[:,1]], s=0)
    u_initial_sample = np.arange(0, 1.01, 0.005)
    out = interpolate.splev(u_initial_sample, tck)
    path_length = get_path_length(out)
    u_final_sample = np.arange(0, 1.0, (speed_mps / sample_rate_hz) / path_length)
    path = interpolate.splev(u_final_sample, tck)
    first_derivative = interpolate.splev(u_final_sample, tck, der=1)
    second_derivative = interpolate.splev(u_final_sample, tck, der=2)
    headings = np.arctan2(first_derivative[1], first_derivative[0])
    curvature = (first_derivative[0] * second_derivative[1] - first_derivative[1] * second_derivative[0]) / np.power(np.square(first_derivative[0]) + np.square(first_derivative[1]), 1.5)
    return path, headings, curvature

def generate_control_points(target_obb: OrientedBoundingBox):
    
    final_veh_pose = VehiclePose(target_obb.centroid_x_m, target_obb.centroid_y_m, target_obb.heading_rad)
    
    point1_x = final_veh_pose.x_m - 2.0
    point1_y = -final_veh_pose.y_m * 0.5
    
    final_pose_offset = np.array([[-abs(final_veh_pose.y_m)*0.75, 0]])
    final_pose_offset_trans = (final_pose_offset @ get_rot_mat(final_veh_pose.theta_rad)).flatten()
    
    # print(final_pose_offset_trans)
    
    point2_x = final_veh_pose.x_m + final_pose_offset_trans[0]
    point2_y = final_veh_pose.y_m + final_pose_offset_trans[1]
    
    point3_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (3/16)
    point3_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (3/16)
    
    point4_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (2/16)
    point4_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (2/16)
    
    point5_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (1/16)
    point5_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (1/16)
    
    control_points = [
        (0, 0),
        (point1_x * (1/16), 0.0),
        (point1_x * (2/16), 0.0),
        (point1_x * (3/16), 0.0),
        (point1_x, point1_y),
        (point2_x, point2_y),
        (point3_x, point3_y),
        (point4_x, point4_y),
        (point5_x, point5_y),
        (final_veh_pose.x_m, final_veh_pose.y_m)
    ]
    
    return control_points

def generate_desired_traj(target_obb: OrientedBoundingBox, speed_mps=1.0, sample_rate_hz=25) -> Trajectory:
    control_points = np.array(generate_control_points(target_obb))
    path, headings, curvatures = cubic_spline(control_points, speed_mps, sample_rate_hz)
    return Trajectory(path, headings, curvatures, control_points, target_obb)

def get_min_separation_between_traj_and_obs(traj: Trajectory, obs_obb: OrientedBoundingBox, num_intermediate_ego = 30):
    
    min_separation = math.inf
    
    # iterate through all number of intermediates to check
    for ego_idx in range(num_intermediate_ego):
        
        # sample index along path to check for collision
        N = len(traj.path[0])
        path_idx = int((N-1) * ego_idx / (num_intermediate_ego - 1))
        
        # construct intermediate obb for ego vehicle
        intermediate_ego_obb = OrientedBoundingBox(traj.path[0][path_idx], traj.path[1][path_idx], traj.target_obb.length_m, traj.target_obb.width_m, traj.headings[path_idx])
        
        # check for collision and min distance
        does_collide, min_intermediate_separation = get_exact_distance_or_overlap(intermediate_ego_obb, obs_obb)
        
        if min_intermediate_separation < min_separation:
            min_separation = min_intermediate_separation
            
    return min_separation

class TrajectoryOptimizer:
    
    def __init__(self, speed_mps=1.0, sample_rate_hz=50, method='BFGS'):
        self.speed_mps = speed_mps
        self.sample_rate_hz = sample_rate_hz
        self.target_obb = None
        self.obstacles = None
        self.initial_traj = None
        self.optimized_traj = None
        self.modifiable_control_point_idxs = []
        self.method = method
        
    def get_traj_cost(self, traj: Trajectory, obstacles: List[OrientedBoundingBox]):
    
        ## == OBSTACLE COST CALCULATION ==
        
        MIN_ALLOWABLE_DISTANCE = 0.3
        OBSTACLE_GROWTH_FACTOR = 1.0
        
        obstacle_separations = np.zeros(len(obstacles))
        
        # for each obstacle, get closest distance between ego following trajectory and the obstacle
        for idx, obstacle_obb in enumerate(obstacles):
            min_separation = get_min_separation_between_traj_and_obs(traj, obstacle_obb)
            obstacle_separations[idx] = min_separation
            # print(f'obstacle min separation: {min_separation:.2f}')
            
        # exponentially penalize traj as it gets closer to min distance allowable distance from obstacles
        obstacle_costs = np.exp(-1 * OBSTACLE_GROWTH_FACTOR * (obstacle_separations - MIN_ALLOWABLE_DISTANCE))
        obstacle_cost = np.sum(obstacle_costs)
        
        ## == MAX CURV CALCULATION ==
        
        # penalize curvatures that have higher mean-squared curvatures
        MAX_ABS_CURV = 1.0
        high_curv_cost = np.max(np.abs(traj.curvatures)) / MAX_ABS_CURV
        
        ## == EFFORT COST CALCULATION ==
        
        # penalize very different trajectories from the original
        MAX_EFFORT = 2.0
        initial_points = self.initial_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        optimized_points = self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        mse_effort = np.mean(np.square(optimized_points - initial_points)) / MAX_EFFORT
        
        ## == WEIGH IT AND SEND IT ==
        
        w_obs = 10.0
        w_curv = 5.0
        w_effort = 0.01

        total_cost = (w_obs * obstacle_cost) + (w_curv * high_curv_cost) + (w_effort * mse_effort)
        # print(f'obstacle cost (norm): {obstacle_costs} | high curv cost (norm): {high_curv_cost} | mse effort cost (norm): {mse_effort} | total cost: {total_cost}')
        
        return total_cost
        
    def update_traj_and_get_cost(self, control_points_flattened):
        
        # regenerate trajectory with new control points
        modified_control_points = control_points_flattened.reshape(-1, 2)
        self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]] = modified_control_points
        path, headings, curvatures = cubic_spline(self.optimized_traj.control_points, self.speed_mps, self.sample_rate_hz)
        self.optimized_traj = Trajectory(path, headings, curvatures, self.optimized_traj.control_points, self.optimized_traj.target_obb)
        
        # get cost of new traj
        return self.get_traj_cost(self.optimized_traj, self.obstacles)
        
    def optimize_trajectory(self, modifiable_control_point_idxs=[4, 6]):
        
        # Determine how many points we're modifying
        self.modifiable_control_point_idxs = modifiable_control_point_idxs
        num_points = self.modifiable_control_point_idxs[1] - self.modifiable_control_point_idxs[0]
        bounds = [(-20, 20)] * num_points * 2 # TODO: come up with a smarter bound for this based on the desired final pose
        
        # get initial set of modifiable control points and copy the initial traj to an optimized traj
        self.optimized_traj = deepcopy(self.initial_traj)
        init_points = self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        
        # solve the optimization problem!
        result = minimize(self.update_traj_and_get_cost, init_points, method=self.method, bounds=bounds) # optimization
        
        return self.optimized_traj
        
    def generate_optimal_trajectory(self, target_obb: OrientedBoundingBox, obstacles: List[OrientedBoundingBox]):
        
        # set state variables
        self.target_obb = target_obb
        self.obstacles = obstacles
        
        # do a first pass run to get initital control point placement
        self.initial_traj = generate_desired_traj(self.target_obb, self.speed_mps, self.sample_rate_hz)
        
        # optimize the trajectory
        self.optimized_traj = self.optimize_trajectory()

def plot_desired_path(traj: Trajectory, obstacles: List[OrientedBoundingBox], num_intermediate_ego = 10):
    
    def get_obstacle_patch(obb: OrientedBoundingBox, color='blue', alpha=0.6):
        
        lower_left_x = obb.centroid_x_m - (obb.length_m / 2)
        lower_left_y = obb.centroid_y_m + (obb.width_m / 2)
        
        edgecolor, facecolor = '', ''
        if color == 'blue':
            edgecolor = 'blue'
            facecolor = 'lightblue'
        elif color == 'red':
            edgecolor = 'red'
            facecolor = 'orange'
        
        rect = matplotlib.patches.Rectangle(
            xy=(-lower_left_y, lower_left_x),
            width=obb.width_m,
            height=obb.length_m,
            angle=np.degrees(obb.heading_rad),
            rotation_point='center',  # Instructs matplotlib to rotate around the center
            edgecolor=edgecolor,
            facecolor=facecolor,
            alpha=alpha,
            linewidth=2
        )
        return rect
    
    # make the plot
    fig, ax = plt.subplots(1)
        
    # plot intermediate ego vehicle obbs along the trajectory
    for ego_idx in range(num_intermediate_ego):
        N = len(traj.path[0])
        path_idx = int((N-1) * ego_idx / (num_intermediate_ego - 1))
        # print(path_idx)
        
        intermediate_ego_obb = OrientedBoundingBox(traj.path[0][path_idx], traj.path[1][path_idx], traj.target_obb.length_m, traj.target_obb.width_m, traj.headings[path_idx])
        intermediate_ego_rect = get_obstacle_patch(intermediate_ego_obb, 'red', 0.2)
        ax.add_patch(intermediate_ego_rect)
    
    # plot trajectory itself (color by curvature)
    sc = ax.scatter(-traj.path[1], traj.path[0], c=traj.curvatures, cmap='viridis', s=10)
    fig.colorbar(sc)
    
    # plot control points as green points
    for point in traj.control_points:
        ax.scatter(*xy_to_plot(point[0], point[1]), marker='o', edgecolor='black', s=50, c='green')
    
    # plot obstacle obbs as blue rectangles with blue dots as centers
    for obs in obstacles:
        rect = get_obstacle_patch(obs)
        ax.add_patch(rect)
        ax.scatter(*xy_to_plot(obs.centroid_x_m, obs.centroid_y_m), marker='o', edgecolor='black', s=50, c='blue')

    # plot stars for initial and final ego poses
    ax.scatter(0, 0, marker='*', edgecolor='black', s=200, c='cyan', label='initial pose')
    ax.scatter(*xy_to_plot(traj.target_obb.centroid_x_m, traj.target_obb.centroid_y_m), marker='*', edgecolor='black', s=200, c='red', label='final pose')
    
    # stylistic things :)
    ax.grid()
    fig.set_size_inches(5, 7)
    
