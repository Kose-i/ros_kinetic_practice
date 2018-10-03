cmake_minimum_required(VERSION 2.8.3)
project(comp_tutorial)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
   FILES
   adder.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(adder_node src/adder.cpp)
target_link_libraries(adder_node ${catkin_LIBRARIES})

add_executable(para_in_node src/para_in.cpp)
target_link_libraries(para_in_node ${catkin_LIBRARIES})
