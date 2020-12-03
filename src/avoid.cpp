#include <ros/ros.h>
#include <gnc_functions.hpp>
#include <sensor_msgs/LaserScan.h>

void scan_cb(const sensor_msgs::LaserScan::ConstPtr& scan){
    sensor_msgs::LaserScan current_2D_scan;
  	current_2D_scan = *scan;
	float avoidance_vector_x = 0; 
	float avoidance_vector_y = 0;
	bool avoid = false;
	int count = current_2D_scan.scan_time / current_2D_scan.time_increment;
	for(int i=1; i<count; i++)
	{
		float d0 = 3; 
		float k = 0.5;

		if(current_2D_scan.ranges[i] < d0 && current_2D_scan.ranges[i] > .35)
		{
			avoid = true;
			float x = cos(current_2D_scan.angle_increment*i);
			float y = sin(current_2D_scan.angle_increment*i);
			float U = -.5*k*pow(((1/current_2D_scan.ranges[i]) - (1/d0)), 2);	

			avoidance_vector_x = avoidance_vector_x + x*U;
			avoidance_vector_y = avoidance_vector_y + y*U;

		}
	}
	//float current_heading = get_current_heading();
	//float deg2rad = (M_PI/180);
	//avoidance_vector_x = avoidance_vector_x*cos((current_heading)*deg2rad) - avoidance_vector_y*sin((current_heading)*deg2rad);
	//avoidance_vector_y = avoidance_vector_x*sin((current_heading)*deg2rad) + avoidance_vector_y*cos((current_heading)*deg2rad);

	if(avoid)
	{
		if( sqrt(pow(avoidance_vector_x,2) + pow(avoidance_vector_y,2)) > 3)
		{
			avoidance_vector_x = 3 * (avoidance_vector_x/sqrt(pow(avoidance_vector_x,2) + pow(avoidance_vector_y,2)));
			avoidance_vector_y = 3 * (avoidance_vector_y/sqrt(pow(avoidance_vector_x,2) + pow(avoidance_vector_y,2)));
		}
		//geometry_msgs::Point current_pos;
		//current_pos = get_current_location();
		//set_destination(avoidance_vector_x + current_pos.x, avoidance_vector_y + current_pos.y, 2, 0);	
		ROS_INFO("Vector X : %f Vector Y : %f",avoidance_vector_x,avoidance_vector_y);
	}
}

int main(int argc, char **argv){
    ros::init(argc,argv, "avoidance_node");
    ros::NodeHandle n;

    ros::Subscriber collision_sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1, scan_cb);
    init_publisher_subscriber(n);

    // wait4connect();
    // wait4start();
    // initialize_local_frame();

    // takeoff(0.5);

    // set_destination(0,0,0.5,0);

    ros::Rate rate(2.0);
    int counter = 0;
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }


    return 0;
}
