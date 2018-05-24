#include <utility>

#include "five_line_game/board.h"
#include <turtlesim/Pose.h>

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
using Point = std::pair<int,int>;

/*
void poseCallback(const five_line_game::board)
{
}
*/
int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_frame");
  ros::NodeHandle nh;

  tf::Transform trans;
  trans.setOrigin(tf::Vector3(0.0,0.0,0.0));
  //tf::StampedTransform(trans, ros::Time::now(), "world");

  Point pos;
  while (ros::ok()){
  std::cin >> pos.first >> pos.second;
  //ros::Subscriber sub = nh.subscribe("black", &poseCallback);
  ROS_INFO("check");

  ros::spin();
  }
  return 0;
}
