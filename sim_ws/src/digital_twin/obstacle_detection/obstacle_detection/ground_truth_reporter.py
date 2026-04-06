import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Float32, Bool
from custom_interfaces.msg import Actor, ActorList
import time, math
import yaml
from pathlib import Path

TIMER_PERIOD_S = 0.1
F1TENTH_GYM_NODE_BASE = Path(__file__).parents[6] / 'src' / 'f1tenth_gym_ros'
MAP_BASE = F1TENTH_GYM_NODE_BASE / 'maps'
MAP_NAME = 'my_custom_map'
    
class GroundTruthReporter(Node):

    def __init__(self, map_name=MAP_NAME):
        super().__init__('ground_truth_reporter')
        self.map_name = map_name
        self.actor_list_msg = ActorList()
        self.actor_msg_publisher = self.create_publisher(ActorList, '/actors', 10)
        self.timer = self.create_timer(TIMER_PERIOD_S, self.msg_publisher_callback)
        self.get_actor_info()
        
    def get_actor_info(self):
        
        actor_info = []
        self.gt_actors = []
        yaml_path_name = MAP_BASE / f'{self.map_name}.yaml'
        with open(yaml_path_name, 'r') as f:
            actor_info = yaml.safe_load(f)['actors']
            
        for actor in actor_info:
            new_actor = Actor()
            new_actor.x = float(actor['x'])
            new_actor.y = actor['y']
            new_actor.theta = actor['theta']
            new_actor.length = actor['length']
            new_actor.width = actor['width']
            self.actor_list_msg.actors.append(new_actor)

    def msg_publisher_callback(self):
        self.actor_msg_publisher.publish(self.actor_list_msg)

def main(args=None):
    rclpy.init(args=args)
    reporter = GroundTruthReporter()
    rclpy.spin(reporter)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
