#include <motor.h>
#include <ros/ros.h>
#include <control/control_cmd.h>


void control_callback(const control::control_cmd& msg){
    std::stringstream act_cmd;
    act_cmd << std::setw(1) << (int)msg.direction << ';';
    act_cmd << std::setfill('0') << std::setw(3) << (int)msg.throttle << ';';
    act_cmd << std::setfill('0') << std::setw(3) << (int)msg.steering << ";.";

    //std::cout << sizeof(act_cmd.str());

    serial_actuator.Write(act_cmd.str());
}

int main(int argc, char** argv) {

    const bool drive_by_actuator = true;

    ros::init(argc, argv, "chassis");
    ros::NodeHandle chassis;
    
    ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_callback);

    ros::spin();

    return 0;
}
