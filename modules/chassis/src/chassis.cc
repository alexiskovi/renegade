#include <ros/ros.h>
#include <control/control_cmd.h>
#include <chassis/chassis_msg.h>
#include <serial.h>
#include <sstream>


renegade::common::SerialInterface serial_actuator("/dev/ttyUSB1");


void control_callback(const control::control_cmd& msg){
    std::stringstream act_cmd;
    act_cmd << std::setw(1) << (int)msg.direction << ';';
    act_cmd << std::setfill('0') << std::setw(3) << (int)msg.throttle << ';';
    act_cmd << std::setfill('0') << std::setw(3) << (int)msg.steering << ";.";

    serial_actuator.Write(act_cmd.str());
}

int main(int argc, char** argv) {

    const bool drive_by_actuator = true;

    ros::init(argc, argv, "chassis");
    ros::NodeHandle chassis;
    
    ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_callback);
    ros::Publisher chassis_pub = chassis.advertise<chassis::chassis_msg>("/renegade/chassis", 5);

    std::string line;

    ros::spin();

    return 0;
}
