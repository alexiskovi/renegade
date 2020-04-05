#include <ublox.h>
#include <serial.h>
#include <iostream>


namespace renegade {
namespace gps {

Ublox::Ublox() {
    ROS_INFO("Launching GPS node");
}

Ublox::~Ublox() {
    ROS_INFO("Stopping GPS node");
}

bool Ublox::GetNewLine(std::string* line) {
    std::string msg;
    if (!ublox_serial.Read(&msg);) return false;
    else{
        line = msg;
        return true;
    }
}

std::vector<double> Ublox::Parse(std::string msg) {
    std::string delimeter = ";";

    auto start = 0U;
    auto end = msg.find(delimeter);

    std::string token;
    std::vector <double> result;

    while ((end != std::string::npos) {
      token = msg.substr(start, end-start);
      double ttoken = std::stod(token);
      result.push_back(ttoken);
      start = end + delimeter.length();
      end = msg.find(delimeter, start)
    }
    result.push_back(msg.substr(start, end-1));
    return result;
}

}
}
