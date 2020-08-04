#include <ros.h>
#include <hello_msgs/Print.h>
#include "mainpp.h"

ros::NodeHandle nh;

hello_msgs::Print msg;
ros::Publisher printer("print_server", &msg);
char document[] = "Article";
char content[] = "Hello from MCU!";

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(printer);
}

void loop(void)
{
  msg.document_name = document;
  msg.content = content;
  printer.publish(&msg);
  nh.spinOnce();

  HAL_Delay(1000);
}
