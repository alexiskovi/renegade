#include <motor.h>
#include <ros/ros.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "chassis");
    ros::NodeHandle chassis;
    ros::Rate loop_rate(100);
    renegade::chassis::Motor motor;
    while (ros::ok()){

        // CONTROL SUBSCRIBER

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}