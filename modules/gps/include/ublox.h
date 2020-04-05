#pragma once
#include "ros/ros.h"
#include <serial.h>
#include <sstream>

renegade::common::SerialInterface ublox_serial("/dev/ttyACM0");

namespace renegade {
namespace gps {

class Ublox {
    public:
    Ublox();
    ~Ublox();
    bool GetNewLine(std::string* line);
    std::vector<double> Parse(std::string msg);
};

}
}
