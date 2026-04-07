import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from ackermann_msgs.msg import AckermannDriveStamped
import time, math

TIMER_PERIOD_S = 0.02

class VehicleController(Node):

    def __init__(self, veh_speed_mps=0.0, steer_angle_rad=0.0):
        super().__init__('vehicle_controller')
        self.drive_cmd_publisher = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.timer = self.create_timer(TIMER_PERIOD_S, self.vehicle_timer_callback)
        self.veh_speed_mps = veh_speed_mps
        self.steer_angle_rad = steer_angle_rad
        
    def sine_speed(self, time_s):
        SPEED_MAG = 0.3
        SPEED_MEAN = 0.5
        SPEED_FREQ_HZ = 0.02
        return SPEED_MAG * math.sin(2 * math.pi * SPEED_FREQ_HZ * time_s) + SPEED_MEAN
    
    def sine_rwa(self, time_s):
        RWA_MAG = 0.1
        RWA_MEAN = 0.0
        RWA_FREQ_HZ = 0.05
        return RWA_MAG * math.sin(2 * math.pi * RWA_FREQ_HZ * time_s) + RWA_MEAN

    def vehicle_timer_callback(self):
        
        msg = AckermannDriveStamped()
        curr_time = time.time()
        
        msg.drive.speed = self.sine_speed(curr_time)
        msg.drive.acceleration = 0.0
        msg.drive.jerk = 0.0
        
        msg.drive.steering_angle = self.sine_rwa(curr_time)
        msg.drive.steering_angle_velocity = 0.0
        
        msg.header.stamp.sec = int(curr_time)
        msg.header.stamp.nanosec = int((curr_time - int(curr_time)) * 1e9)
        
        # print(f'controller speed = {msg.drive.speed:.2f} and angle = {msg.drive.steering_angle:.2f}')
        
        self.drive_cmd_publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    veh_controller = VehicleController(1.0, 0.2)
    rclpy.spin(veh_controller)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
