#include <ublox.h>
#include <serial.h>
#include <iostream>
#include <string>

renegade::common::SerialInterface ublox_serial("/dev/ttyUSB0");

namespace renegade {
namespace gps {

Ublox::Ublox() {
    ROS_INFO("Launching GPS node");
}

Ublox::~Ublox() {
    ROS_INFO("Stopping GPS node");
}

bool Ublox::GetNewLine(std::string * line) {
    //std::string msg = *line;
    if (!ublox_serial.Read(line))
      return false;
    else {
        return true;
    }
}

std::vector<double> Ublox::Parse(std::string msg) {
    std::string delimeter = ";";

    size_t start = 0U;
    size_t end;

    std::string token;
    std::vector <double> result;

    while ((end = msg.find(delimeter, start)) != std::string::npos) {
      token = msg.substr(start, end-start);
      double ttoken = std::stod (token);
      result.push_back(ttoken);
      start = end + delimeter.length();
    }
    result.push_back(std::stod (msg.substr(start, msg.length()-1)));
    return result;
}

}
}
