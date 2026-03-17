import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from ackermann_msgs.msg import AckermannDriveStamped
import time

TIMER_PERIOD_S = 0.02

class VehicleController(Node):

    def __init__(self, veh_speed_mps=0.0, steer_angle_rad=0.0):
        super().__init__('vehicle_controller')
        self.drive_cmd_publisher = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.timer = self.create_timer(TIMER_PERIOD_S, self.vehicle_timer_callback)
        self.veh_speed_mps = veh_speed_mps
        self.steer_angle_rad = steer_angle_rad

    def vehicle_timer_callback(self):
        
        msg = AckermannDriveStamped()
        
        msg.drive.speed = self.veh_speed_mps
        msg.drive.acceleration = 0.0
        msg.drive.jerk = 0.0
        
        msg.drive.steering_angle = self.steer_angle_rad
        msg.drive.steering_angle_velocity = 0.0
        
        curr_time = time.time()
        msg.header.stamp.sec = int(curr_time)
        msg.header.stamp.nanosec = int((curr_time - int(curr_time)) * 1e9)
        
        print(f'controller: {self.veh_speed_mps}')
        
        self.drive_cmd_publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    veh_controller = VehicleController(1.0, 0.2)
    rclpy.spin(veh_controller)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
