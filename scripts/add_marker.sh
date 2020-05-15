#!/bin/sh
#add turtlebot_world.launch
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
#add amcl_demo.launch
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/robond/workspace/catkin_ws/src/RoboND_HomeServiceRobot/map/map.yaml" &
sleep 5
#add view_navigation.launch
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
#Launch node
xterm -e " rosrun add_markers add_markers"
