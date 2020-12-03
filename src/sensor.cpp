#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

#define RAD2DEG(x) ((x)*180./M_PI)

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    sensor_msgs::LaserScan current_2D_scan;
    current_2D_scan = *scan;
    int count = current_2D_scan.scan_time / current_2D_scan.time_increment;
    ROS_INFO("I heard a laser scan %s[%d]:", current_2D_scan.header.frame_id.c_str(), count);
    ROS_INFO("angle_range, %f, %f", RAD2DEG(current_2D_scan.angle_min), RAD2DEG(current_2D_scan.angle_max));
  
    for(int i = 0; i < count; i++) {
        float degree = RAD2DEG(current_2D_scan.angle_min + current_2D_scan.angle_increment * i);
        ROS_INFO(": [%f, %f]", degree, current_2D_scan.ranges[i]);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rplidar_node_client");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);

    ros::spin();

    return 0;
}
