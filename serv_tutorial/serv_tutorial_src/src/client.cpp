#include "ros/ros.h"
#include "serv_tutorial_srv/Add_three_int.h"

#include <cstdlib>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_three_int_client");
  if (argc != 4)
  {
    ROS_INFO("usage: add three client X Y Z");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<serv_tutorial_srv::Add_three_int>("Add_three_ints");
  serv_tutorial_srv::Add_three_int serv;
  serv.request.A = atoll(argv[1]);
  serv.request.B = atoll(argv[2]);
  serv.request.C = atoll(argv[3]);

  if (client.call(serv))
  {
    ROS_INFO("Sum: %ld",(long int)serv.response.Sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_three_int");
    return 1;
  }
  return 0;
}
