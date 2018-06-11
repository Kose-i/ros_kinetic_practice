#include <ros/ros.h>

#include <sensor_msgs/NavSatFix.h>

void callback(const sensor_msgs::NavSatFix& msgs){
  ROS_INFO("latitude = %f, longtitude = %f, altitude = %f", msgs.latitude, msgs.longitude, msgs.altitude);
}
int main(int argc, char** argv){
  ros::init(argc, argv, "gps_server");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/fix", 1000, callback);

  ros::spin();

  return 0;
}
