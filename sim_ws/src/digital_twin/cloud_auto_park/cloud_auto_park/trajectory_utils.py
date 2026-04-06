from dataclasses import dataclass
import matplotlib.pyplot as plt
import math
import numpy as np
from scipy.interpolate import CubicSpline
from scipy import interpolate

@dataclass
class VehiclePose:
    x_m: float = 0.0
    y_m: float = 0.0
    theta_rad: float = 0.0
    
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
    curvature = (first_derivative[0] * second_derivative[1] - first_derivative[1] * second_derivative[0]) / np.power(np.square(first_derivative[0]) + np.square(first_derivative[1]), 1.5)
    return path, curvature

def generate_control_points(final_veh_pose):
    
    point1_x = final_veh_pose.x_m - 2.0
    point1_y = -final_veh_pose.y_m * 0.5
    
    final_pose_offset = np.array([[-abs(final_veh_pose.y_m)*0.75, 0]])
    final_pose_offset_trans = (final_pose_offset @ get_rot_mat(final_veh_pose.theta_rad)).flatten()
    
    # print(final_pose_offset_trans)
    
    point2_x = final_veh_pose.x_m + final_pose_offset_trans[0]
    point2_y = final_veh_pose.y_m + final_pose_offset_trans[1]
    
    point3_x = final_veh_pose.x_m + final_pose_offset_trans[0] / 2
    point3_y = final_veh_pose.y_m + final_pose_offset_trans[1] / 2
    
    point4_x = final_veh_pose.x_m + final_pose_offset_trans[0] *0.35
    point4_y = final_veh_pose.y_m + final_pose_offset_trans[1] *0.35
    
    control_points = [
        (0, 0),
        (point1_x/6, 0.0),
        (point1_x/4, 0.0),
        (point1_x, point1_y),
        (point2_x, point2_y),
        # (point3_x, point3_y),
        (point4_x, point4_y),
        (final_veh_pose.x_m, final_veh_pose.y_m)
    ]
    
    return control_points

def generate_desired_path(final_veh_pose, speed_mps=1.0, sample_rate_hz=25):
    
    control_points = np.array(generate_control_points(final_veh_pose))
    path = cubic_spline(control_points, speed_mps, sample_rate_hz)
    return path

def plot_desired_path(final_veh_pose: VehiclePose):
    
    control_points = generate_control_points(final_veh_pose)
    desired_path, curvature = generate_desired_path(final_veh_pose)
    
    # plt.xlim(-3, 3)
    # plt.ylim(-1, 3)
    plt.grid()
    sc = plt.scatter(-desired_path[1], desired_path[0], c=curvature, cmap='viridis', s=10)

    cbar = plt.colorbar(sc)
    for point in control_points:
        plt.scatter(*xy_to_plot(point[0], point[1]), marker='o', edgecolor='black', s=50, c='green')
    plt.scatter(0, 0, marker='*', edgecolor='black', s=200, c='cyan', label='initial pose')
    plt.scatter(*xy_to_plot(final_veh_pose.x_m, final_veh_pose.y_m), marker='*', edgecolor='black', s=200, c='red', label='final pose')
    plt.gcf().set_size_inches(2, 5)
    # plt.legend()
    
