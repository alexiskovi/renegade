#include <motor.h>
#include <ros/ros.h>
#include <control/control_cmd.h>


void control_callback(const control::control_cmd& msg){
    //if(!motor.set_throttle(msg.throttle)){
    //    ROS_ERROR("Failed to send throttle command");
    //}
}

void control_actuator_callback(const control::control_cmd& msg){
    std::stringstream act_cmd;
    act_cmd << std::setw(1) << msg.direction << ';';
    act_cmd << std::setfill('0') << std::setw(3) << msg.throttle << ';';
    act_cmd << std::setfill('0') << std::setw(3) << msg.steering << ';';
    serial_actuator.Write(act_cmd.str());
}

int main(int argc, char** argv) {

    const bool drive_by_actuator = true;

    ros::init(argc, argv, "chassis");
    ros::NodeHandle chassis;
    

    if (drive_by_actuator){
        ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_actuator_callback);
    }
    else {
        ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_callback);
    }

    ros::spin();

    return 0;
}
