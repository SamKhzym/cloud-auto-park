import rclpy
from rclpy.node import Node
from custom_interfaces.srv import CloudAutoPark
from custom_interfaces.msg import Pose, Point, BicycleModelParams, Trajectory

from .trajectory_utils import VehiclePose, generate_desired_path

class CloudAutoParkService(Node):

    def __init__(self):
        super().__init__('cloud_auto_park')
        self.actors = []
        self.srv = self.create_service(CloudAutoPark, 'cloud_auto_park', self.cloud_auto_park_callback)

    def vbm_params_to_msg(self):
        
        # TODO: make this be dynamic with the online param estimator
        return BicycleModelParams(
            cf=3.3026000070695702, 
            cr=3.819493299820521, 
            mass=2.6181050807024575, 
            lf=0.15875, 
            lr=0.17145, 
            izz=0.061255774235714676
        )
        
    def arrays_to_trajectory(self, xs, ys, curvs):
        
        traj = Trajectory()
        for i in range(len(xs)):
            point = Point()
            point.x = float(xs[i])
            point.y = float(ys[i])
            point.curv = float(curvs[i])
            traj.points.append(point)
        return traj

    def cloud_auto_park_callback(self, request, response):
        
        self.get_logger().info('Incoming request!')
        
        desired_pose = VehiclePose(
            request.finalpose.x,
            request.finalpose.y,
            request.finalpose.theta
        )
        speed_mps = request.speed
        sample_rate_hz = request.sampletime
        
        desired_path, curv = generate_desired_path(
            desired_pose, 
            speed_mps=speed_mps, 
            sample_rate_hz=sample_rate_hz
        )
        
        response.params = self.vbm_params_to_msg()
        response.traj = self.arrays_to_trajectory(desired_path[0], desired_path[1], curv)
        self.get_logger().info('Made a traj, sending it down!')

        return response

def main(args=None):
    rclpy.init(args=args)
    cap_service = CloudAutoParkService()
    rclpy.spin(cap_service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
