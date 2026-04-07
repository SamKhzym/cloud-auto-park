import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Define the node
    controller_node = Node(
        package='cloud_auto_park',
        executable='cloud_auto_park_service', # The name defined in setup.py console_scripts
        name='cloud_auto_park_service',
        output='screen',
        emulate_tty=True,
        parameters=[],
        remappings=[]
    )

    return LaunchDescription([
        controller_node
    ])
