#include <motor.h>
#include <ros/ros.h>
#include <serial.h>
#include <control/control_cmd.h>

void control_callback(const control::control_cmd& msg){
    motor.set_throttle(msg.throttle);
}

void control_actuator_callback(const control::control_cmd& msg){

    serial_actuator.Write(act_cmd);
}

int main(int argc, char** argv) {

    const bool drive_by_actuator = true;

    ros::init(argc, argv, "chassis");
    ros::NodeHandle chassis;
    
    renegade::chassis::Motor motor;
    //renegade::chassis::Servo servo;

    if (drive_by_actuator){
        renegade::common::SerialInterface serial_actuator("/dev/ttyUSB0");
        ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_actuator_callback);
    }
    else {
        ros::Subscriber control_sub = chassis.subscribe("/renegade/control", 5, control_callback);
    }

    ros::spin();

    return 0;
}
