#include "ros/ros.h"
#include "std_msgs/Int16.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arduino_talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int16>("arduino_server", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  //
    std_msgs::Int16 direc;
    //
  while (ros::ok())
  {
    //
    if (count == 0)direc.data = 0;
      //

    //direc.data = 0;

    chatter_pub.publish(direc);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;

    /**/
    switch (direc.data) {
      case 0:direc.data = 1;break;
      case 1:direc.data = 2;break;
      case 2:direc.data = 3;break;
      case 3:direc.data = 0;break;
    }
    /**/
  }


  return 0;
}
