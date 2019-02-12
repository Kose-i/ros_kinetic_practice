cmake_minimum_required(VERSION 2.8.3)
project(action_runner)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  message_generation
  roscpp
  std_msgs

  action_header
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_executable(fibonacci_server src/fibonacci_server.cpp)
add_dependencies(
  fibonacci_server
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(
  fibonacci_server
  ${catkin_LIBRARIES}
)
