#include <mainpp.h>
#include <ros.h>
#include <hello_msgs/Print.h>

ros::NodeHandle nh;

hello_msgs::Print msg;
ros::Publisher printer("print_server", &msg);
char document[] = "Article";
char content[] = "Hello from MCU!";

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
