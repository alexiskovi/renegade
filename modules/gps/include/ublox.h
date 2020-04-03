#include "ros/ros.h"
#include <serial.h>
#include <sstream>

renegade::common::SerialInterface serial_actuator("/dev/ttyUSB0");

namespace renegade {
namespace gps {

class Ublox {
    public:
    Ublox();
    ~Ublox();
    bool GetNewLine();
    vector<double> Parse(string * msg);
};

}
}
