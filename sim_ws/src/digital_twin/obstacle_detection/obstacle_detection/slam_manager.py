import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from data_manager.gps_helpers import world_quat_to_yaw_angle, world_pose_to_local_pose
import time, math
import yaml
from pathlib import Path
import pickle

NS_TO_S = 1e-9
CAPTURE_TIME = 10.0

DT_BASE = Path(__file__).parents[6] / 'src' / 'digital_twin'
SAVE_DATA_LOCATION = DT_BASE / 'obstacle_detection' / 'data'

class SlamManager(Node):

    def __init__(self):
        super().__init__('slam_manager')
        self.scan_data = {
            'metadata': {},
            'times': [],
            'scans': []
        }
        self.pose_data = {
            'times': [],
            'poses': []
        }
        self.done_capturing = False
        self.scan_subscriber = self.create_subscription(LaserScan, '/scan', self.scan_callback, 10)
        self.odom_subscriber = self.create_subscription(Odometry, '/ego_racecar/odom', self.odom_callback, 10)
        self.create_timer(CAPTURE_TIME, self.save_timer_callback)
        self.get_logger().info(f'Capturing for {CAPTURE_TIME}s')

    def scan_callback(self, msg):
        
        if not self.done_capturing:
            
            if len(self.scan_data['metadata']) == 0:
                self.scan_data['metadata']['angle_min'] = msg.angle_min
                self.scan_data['metadata']['angle_max'] = msg.angle_max
                self.scan_data['metadata']['angle_increment'] = msg.angle_increment
                self.scan_data['metadata']['range_min'] = msg.range_min
                self.scan_data['metadata']['range_max'] = msg.range_max
            
            self.scan_data['times'].append(float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec * NS_TO_S))
            self.scan_data['scans'].append(msg.ranges)
            
    def odom_callback(self, msg):
        
        if not self.done_capturing:
            
            orientation = msg.pose.pose.orientation
            x = msg.pose.pose.position.x
            y = msg.pose.pose.position.y
            theta = world_quat_to_yaw_angle(orientation.w, orientation.x, orientation.y, orientation.z)
            
            self.pose_data['times'].append(float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec * NS_TO_S))
            self.pose_data['poses'].append([x, y, theta])
        
    def save_timer_callback(self):
        
        if not self.done_capturing:
        
            with open(SAVE_DATA_LOCATION / f'scan_data_{time.time()}.pkl', 'wb') as f:
                data = { 'scans': self.scan_data, 'poses': self.pose_data }
                pickle.dump(data, f)
                
            self.done_capturing = True
            self.get_logger().info(f'Done capturing lidar data')

def main(args=None):
    rclpy.init(args=args)
    slam_manager = SlamManager()
    rclpy.spin(slam_manager)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
