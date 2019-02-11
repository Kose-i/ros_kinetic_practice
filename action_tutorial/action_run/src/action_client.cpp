#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include "action_header/FibonnachiAction.h"

class TutorialActionClient{
  public:
    TutorialActionClient(const std::string&);
    ~TutorialActionClient();

    void doneCb(const actionlib::SimpleClientGoalState&, const action_header::FibonnachiActionResultConstPtr&);
    void activeCb();
    void feedbackCb(const action_header::FibonnachiFeedbackConstPtr&);

    void send_Fibonnachi();

  private:
    void make_Fibonnachi();
    actionlib::SimpleActionClient<action_header::FibonnachiAction> ac;
    std::string action_name;
    action_header::FibonnachiGoal fibonnachi;
};

int main(int argc, char** argv) {
  ros::init(argc, argv, "action_client");
  ROS_INFO("Start action client");
  TutorialActionClient client(ros::this_node::getName());
  ros::spin();
}

TutorialActionClient::TutorialActionClient(const std::string& name) : ac("action-client",true), action_name(name){
  ROS_INFO("%s waiting for server", action_name.c_str());

  ac.waitForServer();

  ROS_INFO("%s got a server", action_name.c_str());
  make_Fibonnachi();
  ROS_INFO("sent actionGoal to server");
  send_Fibonnachi();
}
TutorialActionClient::~TutorialActionClient() {}
void TutorialActionClient::doneCb(const actionlib::SimpleClientGoalState& state, const action_header::FibonnachiActionResultConstPtr& result) {
  ROS_INFO("Finished in state [%s]", state.toString().c_str());
  ROS_INFO("Result: %d",result->result);
  ros::shutdown();
}
void TutorialActionClient::activeCb() {
  ROS_INFO("Goal just went active...");
}
void TutorialActionClient::feedbackCb(const action_header::FibonnachiFeedbackConstPtr& feedback) {
  ROS_INFO("Got Feedback of Progress to Goal: %d", feedback->progress);
}
void TutorialActionClient::send_Fibonnachi() {
  ac.sendGoal(
    fibonnachi,
    boost::bind(&TutorialActionClient::doneCb, this, _1, _2),
    boost::bind(&TutorialActionClient::activeCb, this),
    boost::bind(&TutorialActionClient::feedbackCb, this, _1)
  );
}
void TutorialActionClient::make_Fibonnachi() {
  fibonnachi.waypoint.push_back(1);
  fibonnachi.waypoint.push_back(1);
  for (auto i = 2;i <= 100;++i) {
    fibonnachi.waypoint.push_back(fibonnachi.waypoint[i - 2] + fibonnachi.waypoint[i - 1]);
  }
}
