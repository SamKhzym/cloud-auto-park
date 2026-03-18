import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry
import time
from .database_manager import DatabaseManager
from .gps_helpers import world_x_to_gps_lat, world_y_to_gps_long, world_w_to_gps_heading

TIMER_PERIOD_S = 0.02

class DataListener(Node):

    def __init__(self):
        super().__init__('data_listener')
        self.drive_cmd_subscriber = self.create_subscription(AckermannDriveStamped, '/drive', self.drive_cmd_rcv_callback, 10)
        self.odom_subscriber = self.create_subscription(Odometry, '/ego_racecar/odom', self.odom_rcv_callback, 10)
        self.dm = DatabaseManager()

    def drive_cmd_rcv_callback(self, msg):
        # print(f'got a drive command! speed = {msg.drive.speed}m/s, steering angle = {msg.drive.steering_angle}rad')
        self.dm.buffer_drive_data(
            timestamp_s=msg.header.stamp.sec + (float(msg.header.stamp.nanosec) / 1e9),
            rwa_rad=msg.drive.steering_angle
        )
        
    def odom_rcv_callback(self, msg):
        # print(f'got an odom reading! speed = {msg.twist.twist.linear.x}m/s, yaw rate = {msg.twist.twist.angular.z}rad/s')
        self.dm.buffer_odom_data(
            timestamp_s=(msg.header.stamp.sec + (float(msg.header.stamp.nanosec) / 1e9)),
            speed_mps=msg.twist.twist.linear.x,
            yawrate_radps=msg.twist.twist.angular.z,
            gps_lat_deg=world_x_to_gps_lat(msg.pose.pose.position.x),
            gps_long_deg=world_y_to_gps_long(msg.pose.pose.position.y),
            gps_heading_deg=world_w_to_gps_heading(msg.pose.pose.orientation.w)
        )

def main(args=None):
    rclpy.init(args=args)
    data_listener = DataListener()
    rclpy.spin(data_listener)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
