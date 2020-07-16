cmake_minimum_required(VERSION 3.0.2)
project(hello_printer)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  hello_msgs
  roscpp
)

catkin_package(
  CATKIN_DEPENDS hello_msgs roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/hello_printer_node.cpp)

set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME server PREFIX "")

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

install(TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES
  launch/printer.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
