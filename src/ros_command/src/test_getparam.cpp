#include <ros/ros.h>

int main(int argc, char** argc) {
  ros::init(argc,argv,"rosparam_set");
  ros::NodeHandle nh;

  int set_test{};
  nh.getParam("/test/paramset", set_test);
  ROS_INFO("%d",set_test);
  return 0;
}
