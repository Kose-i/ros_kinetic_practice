cmake_minimum_required(VERSION 2.8.3)
project(learning_tf)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  roscpp
  tf
  turtlesim
  rospy
)

catkin_package(
)

include_directories(
 ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)
add_executable(turtle_frame_broadcaster src/frame_tf_broadcaster.cpp)

target_link_libraries(
turtle_tf_broadcaster
   ${catkin_LIBRARIES}
)
target_link_libraries(
   turtle_tf_listener
   ${catkin_LIBRARIES}
)
target_link_libraries(
   turtle_frame_broadcaster
   ${catkin_LIBRARIES}
)
