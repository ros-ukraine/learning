#!/usr/bin/env bash

script_file=$(readlink -f "$0")
script_path=$(dirname "$script_file")

firmware_messages=$script_path/../firmware/rosserial/Inc

messages_directory=/tmp/messages
rm -rf $messages_directory
mkdir -p /tmp/messages/Inc

rosrun rosserial_stm32 make_libraries.py $messages_directory

rm -rf $firmware_messages
mkdir -p $firmware_messages

mv $messages_directory/Inc/*.* $firmware_messages
mv $messages_directory/Inc/ros $firmware_messages
mv $messages_directory/Inc/rosapi $firmware_messages
mv $messages_directory/Inc/std_msgs $firmware_messages
mv $messages_directory/Inc/sensor_msgs $firmware_messages
mv $messages_directory/Inc/rosserial_msgs $firmware_messages
mv $messages_directory/Inc/hello_msgs $firmware_messages

rm -rf $messages_directory
