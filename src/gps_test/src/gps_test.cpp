#include <ros/ros.h>

#include <sensor_msgs/NavSatFix.h>

void callback(const sensor_msgs::NavSatFix& msgs){
  /*ROS_INFO("緯度 = %f" , msgs.latitude);
  ROS_INFO("経度 = %f" , msgs.longitude);
  ROS_INFO("高度 = %f" , msgs.altitude);*/
  ROS_INFO("latitude = %f, longtitude = %f, altitude = %f", msgs.latitude, msgs.longitude, msgs.altitude);
}
int main(int argc, char** argv){
  ros::init(argc, argv, "gps_server");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/fix", 1000, callback);

  ros::spin();

  return 0;
}
