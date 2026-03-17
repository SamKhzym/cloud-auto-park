import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry
import time

TIMER_PERIOD_S = 0.02

class DataListener(Node):

    def __init__(self):
        super().__init__('data_listener')
        self.drive_cmd_subscriber = self.create_subscription(AckermannDriveStamped, '/drive', self.drive_cmd_rcv_callback, 10)
        self.odom_subscriber = self.create_subscription(Odometry, '/ego_racecar/odom', self.odom_rcv_callback, 10)

    def drive_cmd_rcv_callback(self, msg):
        print(f'got a drive command! speed = {msg.drive.speed}m/s, steering angle = {msg.drive.steering_angle}rad')
        
    def odom_rcv_callback(self, msg):
        print(f'got an odom reading! speed = {msg.twist.twist.linear.x}m/s, yaw rate = {msg.twist.twist.angular.z}rad/s')

def main(args=None):
    rclpy.init(args=args)
    data_listener = DataListener()
    rclpy.spin(data_listener)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
