cmake_minimum_required(VERSION 2.8.3)
project(comp_tutorial)

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

catkin_package(
   CATKIN_DEPENDS message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

#add_executable(adder_node src/adder.cpp)
#target_link_libraries(adder_node ${catkin_LIBRARIES})
#add_dependencies(adder_node comp_generate_messages_cpp)
#
#add_executable(para_in_node src/para_in.cpp)
#target_link_libraries(para_in_node ${catkin_LIBRARIES})
#add_dependencies(para_in_node comp_generate_messages_cpp)
