cmake_minimum_required(VERSION 2.8.3)
project(pluginlib_tutorial)

find_package(catkin REQUIRED COMPONENTS
  pluginlib
  roscpp
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
add_library(polygon_plugin src/polygon_plugin.cpp)

add_executable(polygon_loader src/polygon_loader.cpp)
target_link_libraries(polygon_loader
  ${catkin_LIBRARIES}
)
