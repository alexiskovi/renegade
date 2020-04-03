#include <ublox.h>
#include <serial.h>
#include <iostream>

namespace renegade {
namespace gps {

Ublox::Ublox() {
    ROS_INFO("Launching GPS node");
    renegade::common::SerialInterface ublox_serial("/dev/ttyACM0");
    /*
    //Creating PWM pinout
    softPwmCreate(FORWARD_PIN, 0, 100);
    softPwmCreate(REVERSE_PIN, 0, 100);
    */
}

Ublox::~Ublox() {
    ROS_INFO("Stopping GPS node");
    /*
    //Stopping PWM
    softPwmWrite(FORWARD_PIN, 0);
    softPwmWrite(REVERSE_PIN, 0);
    */
}

bool GeetNewLine() {
    std::string msg;
    if (!ublox_serial.Read(&msg);) return false;
    else std::cout << msg << std::endl;
    return true;
}

vector<double> Parse(string * msg) {
    std::string delimeter = ";";

    auto start = 0U;
    auto end = msg.find(delimeter);

    std::string token;
    std::vector<double> result;

    while ((end != std::string::npos) {
      token = msg.substr(start, end-start);
      double ttoken = std::stod(token);
      result.push_back(ttoken);
      start = end + delimeter.length();
      end = msg.find(delimeter, start)

    }
    result.push_back(msg.substr(start, end));
    return result;
}



}
}
