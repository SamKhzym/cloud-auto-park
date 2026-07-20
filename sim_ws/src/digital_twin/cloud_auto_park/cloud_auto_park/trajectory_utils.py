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

def cubic_spline(control_points, speed_mps=1.0, sample_rate_hz=50):
    tck,u = interpolate.splprep([control_points[:,0], control_points[:,1]], s=0)
    u_initial_sample = np.arange(0, 1.01, 0.005)
    out = interpolate.splev(u_initial_sample, tck)
    path_length = get_path_length(out)
    u_final_sample = np.arange(0, 1.0, (speed_mps / sample_rate_hz) / path_length)
    path = interpolate.splev(u_final_sample, tck)
    first_derivative = interpolate.splev(u_final_sample, tck, der=1)
    second_derivative = interpolate.splev(u_final_sample, tck, der=2)
    headings = np.arctan2(-1 * first_derivative[1], -1 * first_derivative[0])
    curvature = (first_derivative[0] * second_derivative[1] - first_derivative[1] * second_derivative[0]) / np.power(np.square(first_derivative[0]) + np.square(first_derivative[1]), 1.5)
    return path, headings, curvature

def generate_control_points(target_obb: OrientedBoundingBox):
    
    final_veh_pose = VehiclePose(target_obb.centroid_x_m, target_obb.centroid_y_m, target_obb.heading_rad)
    
    point1_x, point1_y = 0, 0
    point2_x, point2_y = (1/32)*final_veh_pose.x_m, 0
    point3_x, point3_y = (2/32)*final_veh_pose.x_m, 0
    point4_x, point4_y = (3/32)*final_veh_pose.x_m, 0
    point4_2_x, point4_2_y = (4/32)*final_veh_pose.x_m, 0
    
    point5_x = final_veh_pose.x_m + 2.0
    point5_y = -final_veh_pose.y_m * 0.15
    
    final_pose_offset = np.array([[-abs(final_veh_pose.y_m)*0.75, 0]])
    final_pose_offset_trans = (final_pose_offset @ get_rot_mat(-final_veh_pose.theta_rad)).flatten()
    
    point6_x = final_veh_pose.x_m + final_pose_offset_trans[0]
    point6_y = final_veh_pose.y_m + final_pose_offset_trans[1]
    
    point6_2_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (4/32)
    point6_2_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (4/32)
    
    point7_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (3/32)
    point7_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (3/32)
    
    point8_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (2/32)
    point8_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (2/32)
    
    point9_x = final_veh_pose.x_m + final_pose_offset_trans[0] * (1/32)
    point9_y = final_veh_pose.y_m + final_pose_offset_trans[1] * (1/32)
    
    point10_x, point10_y = final_veh_pose.x_m, final_veh_pose.y_m
    
    control_points = [
        (point1_x, point1_y),
        (point2_x, point2_y),
        (point3_x, point3_y),
        (point4_x, point4_y),
        (point4_2_x, point4_2_y),
        (point5_x, point5_y),
        (point6_x, point6_y),
        (point6_2_x, point6_2_y),
        (point7_x, point7_y),
        (point8_x, point8_y),
        (point9_x, point9_y),
        (point10_x, point10_y)
    ]
    
    return control_points

def generate_desired_traj(target_obb: OrientedBoundingBox, speed_mps=1.0, sample_rate_hz=50) -> Trajectory:
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
    
    def __init__(self, speed_mps=1.0, sample_rate_hz=50, method='BFGS', reverse=False):
        self.speed_mps = speed_mps
        self.sample_rate_hz = sample_rate_hz
        self.target_obb = None
        self.obstacles = None
        self.initial_traj = None
        self.optimized_traj = None
        self.modifiable_control_point_idxs = []
        self.method = method
        self.reverse = reverse
        
    def get_traj_cost(self, traj: Trajectory, obstacles: List[OrientedBoundingBox]):
    
        ## == OBSTACLE COST CALCULATION ==
        
        MIN_ALLOWABLE_DISTANCE = 0.25
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
        MAX_ABS_CURV = 0.8
        high_curv_cost = np.max(np.abs(traj.curvatures)) / MAX_ABS_CURV
        
        ## == EFFORT COST CALCULATION ==
        
        # penalize very different trajectories from the original
        MAX_EFFORT = 2.0
        initial_points = self.initial_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        optimized_points = self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        mse_effort = np.mean(np.square(optimized_points - initial_points)) / MAX_EFFORT
        
        ## == WEIGH IT AND SEND IT ==
        
        w_obs = 20.0
        w_curv = 5.0
        w_effort = 0.005

        total_cost = (w_obs * obstacle_cost) + (w_curv * high_curv_cost) + (w_effort * mse_effort)
        # print(f'obstacle cost (norm): {obstacle_costs} | high curv cost (norm): {high_curv_cost} | mse effort cost (norm): {mse_effort} | total cost: {total_cost}')
        
        return total_cost
        
    def update_traj_and_get_cost(self, control_points_flattened):
        
        # regenerate trajectory with new control points
        modified_control_points = control_points_flattened.reshape(-1, 2)
        self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]] = modified_control_points
        path, headings, curvatures = cubic_spline(self.optimized_traj.control_points, self.speed_mps, self.sample_rate_hz)
        if self.reverse:
            curvatures *= -1
        self.optimized_traj = Trajectory(path, headings, curvatures, self.optimized_traj.control_points, self.optimized_traj.target_obb)
        
        # get cost of new traj
        return self.get_traj_cost(self.optimized_traj, self.obstacles)
        
    def optimize_trajectory(self, modifiable_control_point_idxs=[5, 7]):
        
        # Determine how many points we're modifying
        self.modifiable_control_point_idxs = modifiable_control_point_idxs
        num_points = self.modifiable_control_point_idxs[1] - self.modifiable_control_point_idxs[0]
        
        # get initial set of modifiable control points and copy the initial traj to an optimized traj
        self.optimized_traj = deepcopy(self.initial_traj)
        init_points = self.optimized_traj.control_points[self.modifiable_control_point_idxs[0]:self.modifiable_control_point_idxs[1]].flatten()
        
        # solve the optimization problem!
        result = minimize(self.update_traj_and_get_cost, init_points, method=self.method) # optimization
        
        return self.optimized_traj
        
    def generate_optimal_trajectory(self, target_obb: OrientedBoundingBox, obstacles: List[OrientedBoundingBox]):
        
        # set state variables
        self.target_obb = target_obb
        self.obstacles = obstacles
        
        # do a first pass run to get initital control point placement
        self.initial_traj = generate_desired_traj(self.target_obb, self.speed_mps, self.sample_rate_hz)
        
        # optimize the trajectory
        self.optimized_traj = self.optimize_trajectory()

def plot_desired_path(traj: Trajectory, obstacles: List[OrientedBoundingBox], num_intermediate_ego = 10, plot_desired = False):
    
    def get_obstacle_patch(obb: OrientedBoundingBox, color='blue', alpha=0.6, linewidth=2):
        
        lower_left_x = obb.centroid_x_m - (obb.length_m / 2)
        lower_left_y = obb.centroid_y_m + (obb.width_m / 2)
        
        edgecolor, facecolor = '', ''
        if color == 'blue':
            edgecolor = 'blue'
            facecolor = 'lightblue'
        elif color == 'darkblue':
            edgecolor = 'darkblue'
            facecolor = 'blue'
        elif color == 'orange':
            edgecolor = 'red'
            facecolor = 'orange'
        elif color == 'red':
            edgecolor = 'darkred'
            facecolor = 'red'
        
        rect = matplotlib.patches.Rectangle(
            xy=(-lower_left_y, lower_left_x),
            width=obb.width_m,
            height=obb.length_m,
            angle=np.degrees(obb.heading_rad),
            rotation_point='center',  # Instructs matplotlib to rotate around the center
            edgecolor=edgecolor,
            facecolor=facecolor,
            alpha=alpha,
            linewidth=linewidth
        )
        return rect
    
    # make the plot
    fig, ax = plt.subplots(1)
    ax.set_aspect('equal')
    
    # put two blue rectangles at the initial and final vehicle poses
    start_ego_obb_patch = get_obstacle_patch(OrientedBoundingBox(traj.path[0][0], traj.path[1][0], traj.target_obb.length_m, traj.target_obb.width_m, 0.0), color='blue', alpha=1.0, linewidth=3.5)
    ax.add_patch(start_ego_obb_patch)
    
    if plot_desired:
        end_ego_obb_patch = get_obstacle_patch(OrientedBoundingBox(traj.path[0][-1], traj.path[1][-1], traj.target_obb.length_m, traj.target_obb.width_m, traj.headings[-1]), color='blue', alpha=1.0, linewidth=3.5)
        ax.add_patch(end_ego_obb_patch)
        
    # plot intermediate ego vehicle obbs along the trajectory
    for ego_idx in range(num_intermediate_ego):
        N = len(traj.path[0])
        path_idx = int((N-1) * ego_idx / (num_intermediate_ego - 1))
        # print(path_idx)
        
        intermediate_ego_obb = OrientedBoundingBox(traj.path[0][path_idx], traj.path[1][path_idx], traj.target_obb.length_m, traj.target_obb.width_m, traj.headings[path_idx])
        intermediate_ego_rect = get_obstacle_patch(intermediate_ego_obb, 'blue', 0.15)
        ax.add_patch(intermediate_ego_rect)
    
    # plot obstacle obbs as orange rectangles with red dots as centers
    for i, obs in enumerate(obstacles):
        label = 'Obstacle Pose' if i == 0 else None
        rect = get_obstacle_patch(obs, color='orange', alpha=1.0, linewidth=3.5)
        ax.add_patch(rect)
        ax.scatter(*xy_to_plot(obs.centroid_x_m, obs.centroid_y_m), marker='o', edgecolor='black', s=50, c='red', label=label)
    
    # plot trajectory itself (color by curvature)
    sc = ax.scatter(-traj.path[1], traj.path[0], c=traj.curvatures, cmap='plasma', s=10)
    cbar = fig.colorbar(sc)
    cbar.set_label('Curvature (1/m)')
    
    # plot control points as green points
    for i, point in enumerate(traj.control_points):
        label = 'Spline Data Point' if i == 0 else None
        ax.scatter(*xy_to_plot(point[0], point[1]), marker='o', edgecolor='black', s=50, c='green', label=label)

    # plot stars for initial and final ego poses
    ax.scatter(0, 0, marker='*', edgecolor='black', s=200, c='cyan', label='Initial Ego Pose')
    ax.scatter(*xy_to_plot(traj.target_obb.centroid_x_m, traj.target_obb.centroid_y_m), marker='*', edgecolor='black', s=200, c='red', label='Desired Ego Pose')
    
    # stylistic things :)
    ax.grid()
    fig.set_size_inches(7, 7)
    ax.set_xlabel('Lateral Distance (m)')
    ax.set_ylabel('Longitudinal Distance (m)')
    ax.legend()
    fig.set_tight_layout(True)
    
    return fig, ax
