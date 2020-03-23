cmake_minimum_required(VERSION 2.8.3)
project(common)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}
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

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)