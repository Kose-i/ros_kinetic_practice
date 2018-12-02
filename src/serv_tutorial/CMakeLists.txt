cmake_minimum_required(VERSION 2.8.3)
project(serv_tutorial)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_service_files(
   FILES
   Add_three_int.srv
)

generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(serve_node src/serv.cpp)
target_link_libraries(serve_node ${catkin_LIBRARIES})

add_executable(client_node src/client.cpp)
target_link_libraries(client_node ${catkin_LIBRARIES})
