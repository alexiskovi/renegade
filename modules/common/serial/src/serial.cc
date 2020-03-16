#include <stdio.h>
#include "serial.h"

namespace renegade {
namespace common {

SerialInterface::SerialInterface(const char port[]) {
    std::ifstream serial_port (port);
    if(!serial_port.is_open()) {
        ROS_ERROR("Can't open serial port");
        return;
    }
    else {
        ROS_INFO("Opened");
    }
}

//void SerialInterface::Write(unsigned char msg[]) {
//    write(serial_port, msg, sizeof(msg));
//}

std::string SerialInterface::Read() {
    std::string msg;
    for(serial_port >> msg; !serial_port.eof(); serial_port >> msg);
    return msg;
}

SerialInterface::~SerialInterface() {
    serial_port.close();
    ROS_INFO("Closed port");
}

}
}