#pragma once
#include <string>
#include <fstream>
#include "ros/console.h"
#include <ros/ros.h>

namespace renegade {
namespace common {

class SerialInterface {
    public:
    SerialInterface(const char *port);
    ~SerialInterface();
    void Write(std::string msg);
    bool Read(std::string* msg);
    protected:
    std::fstream serial_port;
};

}
}
