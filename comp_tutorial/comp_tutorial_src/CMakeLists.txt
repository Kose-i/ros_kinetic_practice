cmake_minimum_required(VERSION 2.8.3)
project(comp_tutorial_src)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  comp_tutorial_msg
)

catkin_package(
   CATKIN_DEPENDS
   comp_tutorial_msg
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(adder_node src/adder.cpp)
add_dependencies(adder_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(adder_node ${catkin_LIBRARIES})

add_executable(para_in_node src/para_in.cpp)
add_dependencies(para_in_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(para_in_node ${catkin_LIBRARIES})
