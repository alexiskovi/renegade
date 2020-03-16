cmake_minimum_required(VERSION 2.8.3)
project(common)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src
  include
)

add_library(${PROJECT_NAME} src/serial.cc)
add_executable(serial_read_test src/serial_read_test.cc)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)

target_link_libraries(serial_read_test
${catkin_LIBRARIES}
${PROJECT_NAME}
)