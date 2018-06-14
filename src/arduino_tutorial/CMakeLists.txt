cmake_minimum_required(VERSION 2.8.3)
project(arduino_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
#  rospy
  std_msgs
)


catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/arduino_tutorial.cpp)

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
)

