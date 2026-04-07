from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # 1. Locate the launch files in other packages
    controller_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('vehicle_controller'), '/launch', '/manual_controller.launch.py'
        ])
    )

    obstacle_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('obstacle_detection'), '/launch', '/gt_reporter.launch.py'
        ])
    )

    cap_srv_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('cloud_auto_park'), '/launch', '/cloud_auto_park_service.launch.py'
        ])
    )
    
    data_manager_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('data_manager'), '/launch', '/data_manager.launch.py'
        ])
    )

    # 2. Return them all in one list
    return LaunchDescription([
        controller_launch,
        obstacle_launch,
        cap_srv_launch,
        data_manager_launch
        # You can also add individual nodes here if they don't have their own launch files
    ])
