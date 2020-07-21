cmake_minimum_required(VERSION 2.8.3)
project(hello_hardware)

find_package(catkin REQUIRED)

catkin_package(
  CATKIN_DEPENDS rosserial_stm32 rosserial_python
)

install(FILES
  launch/serial.launch
  launch/network.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
