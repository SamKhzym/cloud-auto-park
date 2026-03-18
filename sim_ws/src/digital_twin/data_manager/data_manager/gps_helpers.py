import math

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

def world_w_to_gps_heading(ego_orientation_rot):
    return (ego_orientation_rot * 180.0) + 180.0
