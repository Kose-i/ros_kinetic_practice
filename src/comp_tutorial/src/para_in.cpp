#include "ros/ros.h"
#include "comp_tutorial/adder.h"

#include <random>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "para_in");
  ros::NodeHandle n;

  ros::Publisher para_pub = n.advertise<comp_tutorial::adder>("para_in",100);
  ros::Rate loop_rate(1);

  std::random_device rng;
  while (ros::ok())
  {
    comp_tutorial::adder msg;
    msg.a = rng();
    msg.b = rng();

    para_pub.publish(msg);
    ROS_INFO("a:%d + b:%d ",msg.a, msg.b);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
