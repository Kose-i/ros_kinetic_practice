cmake_minimum_required(VERSION 2.8.3)
project(action_header)

find_package(catkin REQUIRED COMPONENTS
#  actionlib
  actionlib_msgs
#  message_generation
#  std_msgs
)

## Generate actions in the 'action' folder
add_action_files(
  DIRECTORY action
  FILES Fibonacci.action
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs  std_msgs
)

catkin_package(
  CATKIN_DEPENDS actionlib_msgs
)
