#pragma once
#include <string>
#include <fstream>
#include "ros/console.h"
#include <ros/ros.h>

namespace renegade {
namespace common {

class SerialInterface {
    public:
    SerialInterface(const char port[]);
    ~SerialInterface();
    //void Write(unsigned char msg[]);
    std::string Read();
    protected:
    std::ifstream serial_port;
};

}
}