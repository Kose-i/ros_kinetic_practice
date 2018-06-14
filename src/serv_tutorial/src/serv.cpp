#include "ros/ros.h"
#include "serv_tutorial/Add_three_int.h"

bool add(serv_tutorial::Add_three_int::Request& req, serv_tutorial::Add_three_int::Response& res)
{
  res.Sum = req.A + req.B + req.C;
  ROS_INFO("request: x = %ld, y = %ld , z = %ld",(long int)req.A, (long int)req.B, (long int)req.C);
  ROS_INFO("sending back response: [%ld]", (long int)res.Sum );
  return true;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_three_int_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("Add_three_ints",add);
  ROS_INFO("Ready to three int");
  ros::spin();
  return 0;
}
