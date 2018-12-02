#include <ros/ros.h>

#include <thread>
#include <chrono>

int main(int argc, char** argv) {

  ros::init(argc ,argv ,"rosparam_set");
  ros::NodeHandle nh;

  int set_test{};
  nh.getParam("/test/paramset", set_test);

  std::this_thread::sleep_for(std::chrono::seconds(3));
  ROS_INFO("%d",set_test);
  return 0;
}
