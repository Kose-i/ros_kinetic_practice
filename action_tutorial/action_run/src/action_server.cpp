#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>

#include "action_header/FibonnachiAction.h"

class TutorialActionServer{
  public:
    TutorialActionServer();
    ~TutorialActionServer();
    void goalCb();
    void preemptCb();
  private:
};
