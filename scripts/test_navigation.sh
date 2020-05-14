#!/bin/sh
#add turtlebot_world.launch
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
#add amcl_demo.launch
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch" &
#add view_navigation.launch
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch"
