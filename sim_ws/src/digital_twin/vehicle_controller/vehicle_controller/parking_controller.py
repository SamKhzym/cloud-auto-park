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
        self.odom_subscriber = self.create_subscription(ActorList, '/actors', self.actor_rx_callback, 10)
        self.cli = self.create_client(CloudAutoPark, 'cloud_auto_park')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        while self.desired_pose is None:
            self.get_logger().info('waiting for desired pose...')
        self.req = CloudAutoPark.Request()
        
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
        self.req.finalpose = self.desired_pose
        self.req.sample_time = CONTROLLER_SAMPLETIME_S
        self.req.speed = SPEED_MPS
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def main(args=None):
    rclpy.init(args=args)

    cap_client = CloudAutoParkAsync()
    response = cap_client.send_request()
    
    # TODO: now that we have the path, need to setup the listeners to get the car
    # to localize itself in its new frame of reference correctly and hook up all
    # the publishing interfaces. Yeah this'll have to come a little later.
    
    cap_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
