cmake_minimum_required(VERSION 2.8.3)
project(serv_tutorial_src)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  serv_tutorial_srv
)

catkin_package(
  CATKIN_DEPENDS
    serv_tutorial_srv
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(serve_node src/serv.cpp)
add_dependencies(serve_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(serve_node ${catkin_LIBRARIES})

add_executable(client_node src/client.cpp)
add_dependencies(client_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(client_node ${catkin_LIBRARIES})
