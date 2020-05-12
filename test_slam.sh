#!/bin/sh
xterm  -e  " source /opt/ros/kinetic/setup.bash;" & 
sleep 5
xterm  -e  " source ../../catkin_ws/devel/setup.bash; cd catkin_ws; catkin_make; roslaunch turtlebot_gazebo turtlebot_world.launch" 
sleep 50
 
