#include "ros/ros.h"
#include "comp_tutorial/adder.h"

void chatterCallback(const comp_tutorial::adder msg)
{
  unsigned int result = msg.a + msg.b;
  ROS_INFO("a:%d + b:%d = %d\n",msg.a , msg.b , result);
}

int main(int argc ,char** argv)
{
  ros::init(argc, argv, "adder");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("para_in",100,chatterCallback);

  ros::spin();

  return 0;
}
