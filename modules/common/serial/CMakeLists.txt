cmake_minimum_required(VERSION 2.8.3)
project(serial)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
  src
)

add_library(${PROJECT_NAME} src/serial.cc)

add_executable(serial_read_test src/serial_read_test.cc)
add_executable(serial_write_test src/serial_write_test.cc)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)

target_link_libraries(serial_read_test
${catkin_LIBRARIES}
${PROJECT_NAME}
)

target_link_libraries(serial_write_test
${catkin_LIBRARIES}
${PROJECT_NAME}
)

#install(DIRECTORY include/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  FILES_MATCHING PATTERN "*.h")
