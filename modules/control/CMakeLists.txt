cmake_minimum_required(VERSION 2.8.3)
project(control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  std_msgs
  message_generation
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src
  include
)

add_message_files(
  FILES
  control_cmd.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

#add_executable(${PROJECT_NAME} src/main.cc src/motor.cc)

#target_link_libraries(${PROJECT_NAME}
#${catkin_LIBRARIES}
#)