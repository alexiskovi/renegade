cmake_minimum_required(VERSION 2.8.3)
project(gps)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  serial
  message_generation
)

add_message_files(
  FILES
  gps_msg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src
  include
)

add_executable(${PROJECT_NAME} src/gps.cc src/ublox.cc)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)
