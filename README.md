# ROS Learning

ROS Learning Materials

[![License](https://img.shields.io/github/license/ros-ukraine/learning.svg)](https://github.com/ros-ukraine/learning/blob/kinetic-devel/LICENSE)


## ROS Basics

### Environment

Please install Docker using [these instructions](https://docs.docker.com/get-docker/)

Get the latest Docker images
```bash
docker pull rosukraine/learning:xenial-kinetic
```

*Please note: On OS Windows you should switch your Docker Engine to Linux containers mode*


Launch docker container using the following command
```bash
docker run -d --name ros_basics -p 8080:8080 -p 8181:8181 -p 8282:8282 rosukraine/learning:xenial-kinetic 
```

You could stop this container using command
```bash
docker stop ros_basics
```

To start container again please type
```bash
docker start ros_basics
```

### Tasks

Boilerplate code is located in ros_basics folder.
