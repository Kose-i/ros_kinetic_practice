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

# add_executable(${PROJECT_NAME}_node src/pluginlib_tutorial_node.cpp)
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )
