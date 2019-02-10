cmake_minimum_required(VERSION 2.8.3)
project(action_tutorial)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  roscpp
  actionlib
)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs actionlib_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_dependencies(${PROJECT_NAME}_client src/action_client.cpp)

target_link_libraries(${PROJECT_NAME}_client
  ${catkin_LIBRARIES}
)
