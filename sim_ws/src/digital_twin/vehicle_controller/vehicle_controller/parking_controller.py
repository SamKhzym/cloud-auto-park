import sys

from custom_interfaces.srv import CloudAutoPark
from custom_interfaces.msg import ActorList, Actor, Pose
import rclpy
from rclpy.node import Node

from .mpc import CONTROLLER_SAMPLETIME_S, MpcController, VehicleBicycleModelParams
SPEED_MPS = 0.3

class CloudAutoParkAsync(Node):

    def __init__(self):
        super().__init__('cloud_auto_park_async')
        self.desired_pose = None
        self.init_timer = self.create_timer(0.1, self.check_readiness_callback)
        self.odom_subscriber = self.create_subscription(ActorList, '/actors', self.actor_rx_callback, 10)
        self.cli = self.create_client(CloudAutoPark, 'cloud_auto_park')
        self.req = CloudAutoPark.Request()
        self.ready = False
        
    def check_readiness_callback(self):
        if self.desired_pose is not None and self.cli.service_is_ready():
            self.get_logger().info('Everything ready!')
            self.ready = True
        
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

    def send_request(self):
        
        self.get_logger().info('Sending request!')
        self.req.finalpose = self.desired_pose
        self.req.sampletime = CONTROLLER_SAMPLETIME_S
        self.req.speed = SPEED_MPS
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        self.response = self.future.result()
        self.get_logger().info('Response received!')
        
    def run_controller(self):
        print(self.response)
        print('doin the ting')

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
    
    cap_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
