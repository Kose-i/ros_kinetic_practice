cmake_minimum_required(VERSION 2.8.3)
project(ros_command)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/test_getparam.cpp
)
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
