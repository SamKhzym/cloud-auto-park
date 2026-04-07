import math
from transforms3d import euler
import numpy as np

# GPS coordinates of the world origin (0,0)
INIT_LAT_DEG = 43.25592690280987
INIT_LONG_DEG = -79.90246093998094

# radius of earth in m
R = 6.3781E6

def degrees(angle_rad):
    return angle_rad * 180.0 / math.pi

def radians(angle_deg):
    return angle_deg * math.pi / 180.0

def world_x_to_gps_lat(x_ego_m):
    return degrees(x_ego_m / R) + INIT_LAT_DEG

def world_y_to_gps_long(y_ego_m):
    y_ego_m_trans = -y_ego_m # transform world y to long coord frame by flipping value
    arcsin_term = math.sin(y_ego_m_trans / (2 * R)) / math.cos(radians(INIT_LAT_DEG))
    return degrees(2 * math.asin(arcsin_term)) + INIT_LONG_DEG

def get_rot_mat(theta):
    return np.array([[np.cos(theta), np.sin(theta)], [-np.sin(theta), np.cos(theta)]])

def world_pose_to_local_pose(ego_x, ego_y, ego_theta, world_x, world_y, world_theta):
    dx = world_x - ego_x
    dy = world_y - ego_y
    dtheta = world_theta - ego_theta
    rot_mat = get_rot_mat(ego_theta)
    local_coord = (rot_mat @ np.array([[dx],[dy]])).flatten()
    return local_coord[0], local_coord[1], dtheta

def world_quat_to_yaw_angle(w, x, y, z):
    _, _, theta = euler.quat2euler([w, x, y, z], axes='sxyz')
    return theta

def world_quat_to_gps_heading(w, x, y, z):
    theta = world_quat_to_yaw_angle(w, x, y, z)
    return ((-degrees(theta) + 360) % 360)

