#include "sensor_msgs/JointState.h"
#include "tf/transform_broadcaster.h"
#include <string>
#include <ros/ros.h>

int main (int argc, char** argv)
{
  ros::init(argc, argv, "urdf_node");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<sensor_msgs::JointState>("joint_state",1);
  tf::TransformBroadcaster tbc;

  geometry_msgs::TransformStamped tsm;
  sensor_msgs::JointState jsm;
  tsm.header.frame_id = "base";
  tsm.child_frame_id = "first_arm";

  jsm.name.resize(2);
  jsm.position.resize(2);
  jsm.name[0] = "base_to_first";

  ros::Rate rate(10);

  while (ros::ok()) {
    jsm.header.stamp  = ros::Time::now();
    jsm.position[0] = 0;

    tsm.header.stamp = ros::Time::now();
    tsm.transform.translation.x = 0;
    tsm.transform.translation.y = 0;
    tsm.transform.translation.z = 0;
    tsm.transform.rotation = tf::createQuaternionMsgFromYaw(0);

    pub.publish(jsm);
    tbc.sendTransform(tsm);

    rate.sleep();
  }
  return 0;
}
