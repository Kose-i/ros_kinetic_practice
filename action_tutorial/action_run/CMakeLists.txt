cmake_minimum_required(VERSION 2.8.3)
project(action_tutorial)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  roscpp
  actionlib
  action_header
)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs actionlib_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_client src/action_client.cpp)
add_dependencies(${PROJECT_NAME}_client ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_client
  ${catkin_LIBRARIES}
)

#add_executable(${PROJECT_NAME}_server src/action_server.cpp)
#add_dependencies(${PROJECT_NAME}_server ${catkin_EXPORTED_TARGETS})
#target_link_libraries(${PROJECT_NAME}_server
#  ${catkin_LIBRARIES}
#)
