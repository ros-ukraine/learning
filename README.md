# ROS Learning

ROS Learning Materials

[![License](https://img.shields.io/github/license/ros-ukraine/learning.svg)](https://github.com/ros-ukraine/learning/blob/kinetic-devel/LICENSE)


## ROS Basics

### Environment

Please install Docker using [these instructions](https://docs.docker.com/get-docker/)

Get the latest Docker images
```bash
docker pull rosukraine/learning:ros_basics
```

*Please note: On OS Windows you should switch your Docker Engine to Linux containers mode*


Launch docker container using the following command
```bash
docker run -d --name ros_basics -p 8080:8080 -p 8181:8181 -p 8282:8282 rosukraine/learning:ros_basics 
```

You could stop this container using command
```bash
docker stop ros_basics
```

To start container again please type
```bash
docker start ros_basics
```

You could access Cloud9 web IDE in any modern browser by opening this link [http://localhost:8181](http://localhost:8181)

### Tasks

Boilerplate code is located in ros_basics folder.

#### Task 4

##### Installation of STM32 ROSSerial

Please clone *https://github.com/yoneken/rosserial_stm32* into your workspace.


##### STM32CubeIDE Project Setup

Use script example for STM32 message file generation
```bash
rosrun hello_hardware make_library.sh
```

Select C++ Project type.
In case if you missed this step you could always convert project to C++.

Add rosserial/Inc directory as a "Source Location" in the project properties (C/C++ General > Paths and Symbols > Source Location)

In Cube window setup USART (by default it is USART2) using the following steps:

* Enable USARTx and select TX and RX pins
* Enable USARTx global interrupt
* Enable DMA for USARTx_TX and USARTx_RX 
  * Set both DMA priority to HIGH
  * Set mode to **Circular** in RX DMA

Please use appropriate definition for your board type in ros_basics/task_4/hello_hardware/firmware/rosserial/Inc/STM32Hardware.h
```cpp
#define STM32F4xx  // Change for your device
```

In the same file it is also possible to change USART device which is used for communication by altering default constructor
```cpp
public:
  STM32Hardware():
    huart(&huart2), rind(0), twind(0), tfind(0) {
  }
```

##### In order to run Serial to TCP bridge:
 
1. Install pySerial package on host OS by running this command
```bash
pip install pyserial
```

2. Find location of pyserial package on your disk

3. Change you path in command line tool to folder examples

4. Launch ROS serial server node using this launch file as an example
```bash

roslaunch hello_hardware network.launch port:=8282
```

5. Launch bridge in client mode
```bash
python ./tcp_serial_redirect.py -c localhost:8282 /dev/ttyUSB0 115200
```

