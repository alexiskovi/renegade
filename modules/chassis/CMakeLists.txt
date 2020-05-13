cmake_minimum_required(VERSION 2.8.3)
project(chassis)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  control
  std_msgs
  message_generation
)

add_message_files(
  FILES
  chassis_msg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime
)

#find_library(wiringPi_LIB wiringPi)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src
  include
)

add_executable(${PROJECT_NAME} src/chassis.cc)

add_executable(vehicle_state_provider src/vehicle_state.cc)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)

target_link_libraries(vehicle_state_provider
${catkin_LIBRARIES}
)