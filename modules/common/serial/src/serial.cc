#include <stdio.h>
#include "serial.h"

namespace renegade {
namespace common {

SerialInterface::SerialInterface(const char *port) {
    serial_port.open(port);
    if(!serial_port.is_open()) {
        ROS_ERROR("Can't open serial port");
    }
    else {
        ROS_INFO("Opened");
    }
}

//void SerialInterface::Write(unsigned char msg[]) {
//    write(serial_port, msg, sizeof(msg));
//}

bool SerialInterface::Read(std::string *msg) {
    serial_port >> *msg;
    if(msg->empty()) return false;
    else return true;
}

SerialInterface::~SerialInterface() {
    serial_port.close();
    ROS_INFO("Closed port");
}

}
}