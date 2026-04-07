import sys

from custom_interfaces.srv import CloudAutoPark
from custom_interfaces.msg import ActorList, Actor, Pose
from ackermann_msgs.msg import AckermannDriveStamped
from nav_msgs.msg import Odometry
import rclpy
from rclpy.node import Node
from data_manager.gps_helpers import world_quat_to_yaw_angle, world_pose_to_local_pose
import numpy as np
from copy import deepcopy
import time

from .mpc import MpcController, VehicleBicycleModelParams

# MPC PARAMETERS
SPEED_MPS = 0.8
HORIZON = 10
SAMPLE_RATE_HZ = 50

class CloudAutoParkAsync(Node):

    def __init__(self):
        super().__init__('cloud_auto_park_async')
        self.desired_pose = None
        self.init_ego_pose = None
        self.ego_pose = None
        self.first_odom_rxd = False
        self.init_timer = self.create_timer(0.1, self.check_readiness_callback)
        self.mpc_timer = self.create_timer((1 / SAMPLE_RATE_HZ), self.mpc_step)
        self.actor_subscriber = self.create_subscription(ActorList, '/actors', self.actor_rx_callback, 10)
        self.odom_subscriber = self.create_subscription(Odometry, '/ego_racecar/odom', self.odom_callback, 10)
        self.drive_cmd_publisher = self.create_publisher(AckermannDriveStamped, '/drive', 10)
        self.cli = self.create_client(CloudAutoPark, 'cloud_auto_park')
        self.req = CloudAutoPark.Request()
        self.ready = False
        self.mpc = None
        self.path_length = 0
        
    def check_readiness_callback(self):
        if self.desired_pose is not None and self.ego_pose is not None and self.cli.service_is_ready():
            self.get_logger().info('Everything ready!')
            self.ready = True
            self.init_timer.cancel()
        
    def actor_rx_callback(self, msg):
        
        # TODO: change the actor rx callback to get desired pose from a proper source.
        centroids_x = []
        centroids_y = []
        centroids_theta = []
        for actor in msg.actors:
            centroids_x.append(actor.x)
            centroids_y.append(actor.y)
            centroids_theta.append(actor.theta)
        self.desired_pose = Pose()
        self.desired_pose.x = sum(centroids_x) / len(centroids_x)
        self.desired_pose.y = sum(centroids_y) / len(centroids_y)
        self.desired_pose.theta = sum(centroids_theta) / len(centroids_theta)
        
    def odom_callback(self, msg):
        self.ego_pose = Pose()
        orientation = msg.pose.pose.orientation
        self.ego_pose.x = msg.pose.pose.position.x
        self.ego_pose.y = msg.pose.pose.position.y
        self.ego_pose.theta = world_quat_to_yaw_angle(orientation.w, orientation.x, orientation.y, orientation.z)
        
        if not self.first_odom_rxd:
            self.init_ego_pose = deepcopy(self.ego_pose)
            self.first_odom_rxd = True
        
    def get_local_desired_pose(self):
        x, y, theta = world_pose_to_local_pose(self.init_ego_pose.x, self.init_ego_pose.y, self.init_ego_pose.theta, self.desired_pose.x, self.desired_pose.y, self.desired_pose.theta)
        local_desired_pose = Pose()
        local_desired_pose.x = x
        local_desired_pose.y = y
        local_desired_pose.theta = theta
        return local_desired_pose
    
    def get_local_ego_pose(self):
        x, y, theta = world_pose_to_local_pose(self.init_ego_pose.x, self.init_ego_pose.y, self.init_ego_pose.theta, self.ego_pose.x, self.ego_pose.y, self.ego_pose.theta)
        return np.array([[x],[y],[theta]])

    def send_request(self):
        
        self.get_logger().info('Sending request!')
        self.req.finalpose = self.get_local_desired_pose()
        self.req.sampletime = float(SAMPLE_RATE_HZ)
        self.req.speed = float(SPEED_MPS)
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        self.response = self.future.result()
        self.get_logger().info('Response received!')
        
    def publish_drive_cmd(self, speed, rwa):
        msg = AckermannDriveStamped()
        curr_time = time.time()
        
        msg.drive.speed = speed
        msg.drive.acceleration = 0.0
        msg.drive.jerk = 0.0
        
        msg.drive.steering_angle = rwa
        msg.drive.steering_angle_velocity = 0.0
        
        msg.header.stamp.sec = int(curr_time)
        msg.header.stamp.nanosec = int((curr_time - int(curr_time)) * 1e9)
        
        # print(f'controller speed = {msg.drive.speed:.2f} and angle = {msg.drive.steering_angle:.2f}')
        
        self.drive_cmd_publisher.publish(msg)
        
    def run_controller(self):
        
        # construct VBM params struct
        params = VehicleBicycleModelParams(
            self.response.params.cf,
            self.response.params.cr,
            self.response.params.mass,
            self.response.params.lf,
            self.response.params.lr,
            self.response.params.izz
        )
        
        # construct desired path data
        xs, ys, curvs = [], [], []
        for point in self.response.traj.points:
            xs.append(point.x)
            ys.append(point.y)
            curvs.append(point.curv)
        xs, ys, curvs = np.array(xs), np.array(ys), np.array(curvs)
        self.path_length = len(xs)
        
        # instantiate the mpc controller
        print('made the mpc')
        self.mpc = MpcController(params, HORIZON, SPEED_MPS, SAMPLE_RATE_HZ)
        self.mpc.set_path([xs, ys], curvs)
        
    def mpc_step(self):
        
        if self.mpc is not None and self.mpc.timestep < self.path_length:
        
            print('controller step', self.mpc.timestep)
        
            # get ego pose relative to initial ego pose and set it in the mpc
            curr_pose = self.get_local_ego_pose()
            self.mpc.set_curr_pose(curr_pose)
            
            # step mpc and get rwa command
            curr_delta = self.mpc.step()
            
            # publish drive command
            self.publish_drive_cmd(SPEED_MPS, curr_delta)
            
        else:
            
            self.publish_drive_cmd(0.0, 0.0)
    

def main(args=None):
    rclpy.init(args=args)

    cap_client = CloudAutoParkAsync()
    
    # wait for service to start and actor locations to be rx'd...
    while not cap_client.ready:
        rclpy.spin_once(cap_client)
        
    # send request
    cap_client.send_request()
    
    # execute received path
    cap_client.run_controller()
    
    rclpy.spin(cap_client)
    
    cap_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
