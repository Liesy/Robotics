#include "ros/ros.h"
//https://www.cnblogs.com/IT-cute/p/13232409.html
int main(int argc,char **argv){
	ros::init(argc,argv,"hello_node");
	ros::NodeHandle nh;
	ROS_INFO_STREAM("hello world");
}
