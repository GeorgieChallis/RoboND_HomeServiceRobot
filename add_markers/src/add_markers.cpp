#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <math.h>

visualization_msgs::Marker set_marker(float, float, float);
void getOdom(const nav_msgs::Odometry::ConstPtr& msg);

visualization_msgs::Marker marker;  
float markersizex = 0.2;
float markersizey = 0.3;

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber sub = n.subscribe("odom", 100, getOdom); 

  float pickupx  = 1.0;
  float pickupy  = 1.0;
  float pickupw  = 1.0;

  float dropoffx = -2.0;
  float dropoffy = -1.0;
  float dropoffw = 1.0;

  ros::Time start_time = ros::Time::now();

  while (ros::ok())
  {
    ros::Duration delta_t = ros::Time::now() - start_time;
    double delta_t_sec = delta_t.toSec();

    if (delta_t_sec < 2)
    {
      marker = set_marker(pickupx, pickupy, pickupw); 
      ROS_INFO("Marker appeared for pickup");
    }
    else {

    }
    if (delta_t_sec < 10)
    {
      marker.action = visualization_msgs::Marker::DELETE;
      //ROS_INFO("Marker picked up");
    }
    else if (delta_t_sec < 15){
      marker = set_marker(dropoffx, dropoffy, dropoffw); 
      //ROS_INFO("Marker dropped off");
    }
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
     if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub.publish(marker);

    ros::spinOnce();
  }
}

visualization_msgs::Marker set_marker(float posx, float posy, float orientw){

  visualization_msgs::Marker marker;

  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE
  marker.type = (uint32_t)visualization_msgs::Marker::CUBE;;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  marker.action = visualization_msgs::Marker::ADD;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = markersizex;
  marker.scale.y = markersizey;
  marker.scale.z = 0.2;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.2f;
  marker.color.g = 0.2f;
  marker.color.b = 0.9f;
  marker.color.a = 0.8;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = posx;
  marker.pose.position.y = posy;
  marker.pose.position.z = 0.1;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w =  orientw;

  marker.lifetime = ros::Duration();

  return marker;
}

void getOdom(const nav_msgs::Odometry::ConstPtr& msg){
  float robotx = msg->pose.pose.position.x;
  float roboty = msg->pose.pose.position.y; 
  float robotw = msg->pose.pose.orientation.w;

  ROS_INFO("X: %f\n", robotx);
  ROS_INFO("Y: %f\n", roboty);
}
