cmake_minimum_required(VERSION 2.8.3)
project(learning_tf)

find_package(catkin REQUIRED
  roscpp
  tf
  turtlesim
)

catkin_package()

include_directories(
 ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)
add_executable(turtle_frame_broadcaster src/frame_tf_broadcaster.cpp)
add_executable(carrot_tf_listener src/carrot_tf_listener.cpp)

target_link_libraries(
turtle_tf_broadcaster
   ${catkin_LIBRARIES}
)
target_link_libraries(
   turtle_tf_listener
   ${catkin_LIBRARIES}
)
target_link_libraries(
    carrot_tf_listener
    ${catkin_LIBRARIES}
)
target_link_libraries(
   turtle_frame_broadcaster
   ${catkin_LIBRARIES}
)
