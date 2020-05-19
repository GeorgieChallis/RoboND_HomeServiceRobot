#!/bin/sh
#add turtlebot_world.launch
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/robond/workspace/catkin_ws/src/RoboND_HomeServiceRobot/world/simple-building.world" &
sleep 5
#add amcl_demo.launch
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/robond/workspace/catkin_ws/src/RoboND_HomeServiceRobot/world/map.yaml" &
sleep 5
#add view_navigation.launch
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch"
#Launch pick_objects node
xterm -e " rosrun pick_objects pick_objects"
