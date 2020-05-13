#include <stdio.h>
#include "serial.h"

namespace renegade {
namespace common {

SerialInterface::SerialInterface(const char *port) {
    serial_port.open(port);
    if(!serial_port.is_open()) {
        ROS_FATAL("Can't open serial port");
    }
    else {
        ROS_INFO("Opened");
    }
}

void SerialInterface::Write(std::string msg) {
    serial_port << msg << std::endl;
}

bool SerialInterface::Read(std::string *msg) {
    serial_port >> *msg;
    if(msg->empty()) return false;
    else return true;
}

std::vector<double> SerialInterface::Parse(std::string msg) {
    std::string delimeter = ";";

    size_t start = 0U;
    size_t end;

    std::string token;
    std::vector <double> result;

    while ((end = msg.find(delimeter, start)) != std::string::npos) {
      token = msg.substr(start, end-start);
      double ttoken = std::stod(token);
      result.push_back(ttoken);
      start = end + delimeter.length();
    }
    result.push_back(std::stod (msg.substr(start, msg.length())));
    return result;
}

SerialInterface::~SerialInterface() {
    serial_port.close();
    ROS_INFO("Closed port");
}

}
}
