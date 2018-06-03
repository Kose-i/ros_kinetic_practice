#include <ros/ros.h>

#include <sensor_msgs/NavSatFix.h>

void callback(const sensor_msgs::NavSatFix& msgs){
  ROS_INFO("%f, " , msgs.latitude);
  ROS_INFO("%f, " , msgs.longitude);
  ROS_INFO("%f, " , msgs.altitude);
}
int main(int argc, char** argv){
  ros::init(argc, argv, "gps_server");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/fix", 1000, callback);

  ros::spin();

  return 0;
}
