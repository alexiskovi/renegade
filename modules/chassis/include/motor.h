#include "ros/ros.h"
#include <serial/serial.h>
#include <sstream>

renegade::common::SerialInterface serial_actuator("/dev/ttyUSB0");

namespace renegade {
namespace chassis {

class Motor {
    public:
    Motor();
    ~Motor();
    bool set_throttle(int throttle_cmd);
};

}
}
