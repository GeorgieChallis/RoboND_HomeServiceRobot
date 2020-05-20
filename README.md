# RoboND_ Home Service Robot
The Home Service Robot ROS project simulates a Turtlebot performing a task in a simple Gazebo environment. A marker is generated at a given pick-up location on the map and the robot navigates the environment to retrieve it and deliver it to another designated drop-off point, using Simultaneous Localisation And Mapping (SLAM).

### Build
This project is intended to be built within a [catkin workspace](http://wiki.ros.org/catkin/workspaces#Catkin_Workspaces). To build, clone this repo and ROS packages below into the `catkin_ws/src` folder and run `catkin_make`.

### Dependencies
* `gmapping`: [https://github.com/ros-perception/slam_gmapping](https://github.com/ros-perception/slam_gmapping)
* `turtlebot_teleop`: [https://github.com/turtlebot/turtlebot](https://github.com/turtlebot/turtlebot)
* `turtlebot_rviz_launchers`: [https://github.com/turtlebot/turtlebot_interactions](https://github.com/turtlebot/turtlebot_interactions)
* `turtlebot_gazebo`: [https://github.com/turtlebot/turtlebot_simulator](https://github.com/turtlebot/turtlebot_simulator)

#### 1. Manually Map Environment
Run the `test_slam.sh` script to launch a simple Gazebo world, RViz and Teleop keyboard node. Drive the Turtlebot around the environment with `i`, `j`, `l` and `m` to populate the map with the RGB-D camera and lidar, then run `$ rosrun map_server map_server map.yaml` to save.

#### 2. Test Navigation with RViz 2D Nav Goal
Run the `test_navigation.sh` script to launch the simple world and RViz. Test navigation works with the generated map by clicking on random waypoints with the 2D Nav Goal tool.

#### 3. Run Full Home Service Package
Run the `home_service.sh` script to run all nodes. A blue cuboid marker will be generated at a drop-off point and the robot will collect it and move it to a new drop-off location:

<img src="https://github.com/GeorgieChallis/RoboND_HomeServiceRobot/blob/master/image/Marker%20pickup.png" width="420">
