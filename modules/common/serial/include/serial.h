#pragma once
#include <string>
#include <fstream>
#include "ros/console.h"
#include <ros/ros.h>
#include <sstream>

namespace renegade {
namespace common {

class SerialInterface {
    public:
    SerialInterface(const char *port);
    ~SerialInterface();
    void Write(std::string msg);
    bool Read(std::string* msg);
    std::vector<double> Parse(std::string msg);
    protected:
    std::fstream serial_port;
};

}
}
