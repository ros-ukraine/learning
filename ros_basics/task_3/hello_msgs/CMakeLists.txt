cmake_minimum_required(VERSION 3.0.2)
project(hello_msgs)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  genmsg
  message_generation
  std_msgs
)

add_message_files(
  FILES
  Print.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs
)
