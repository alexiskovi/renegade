cmake_minimum_required(VERSION 2.8.3)
project(chassis)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  sensor_msgs
  serial
  control
)

catkin_package(
  INCLUDE_DIRS include
)

find_library(wiringPi_LIB wiringPi)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src
  include
)

add_executable(${PROJECT_NAME} src/main.cc src/motor.cc)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)
