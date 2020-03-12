#include <motor.h>

namespace renegade {
namespace chassis {

Motor::Motor() {
    ROS_INFO("Launching motor node");
    /*
    //Creating PWM pinout
    softPwmCreate(FORWARD_PIN, 0, 100);
    softPwmCreate(REVERSE_PIN, 0, 100);
    */
}

Motor::~Motor() {
    ROS_INFO("Stopping motor node");
    /*
    //Stopping PWM
    softPwmWrite(FORWARD_PIN, 0);
    softPwmWrite(REVERSE_PIN, 0);
    */
}

bool Motor::set_throttle(int throttle_cmd) {
    if (throttle_cmd < 0) {
        ROS_ERROR("throttle_cmd < 0. Setting 0 to motor");
        throttle_cmd = 0;
    }
    if (throttle_cmd > 100) {
        ROS_ERROR("throttle_cmd > 100. Setting 100 to motor");
        throttle_cmd = 100;
    }

    /*
    PWM PIN DRIVER HERE
    */

    return true;
}

}
}