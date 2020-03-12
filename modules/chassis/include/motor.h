#include "ros/ros.h"
#include <wiringPi.h>
#include <softPwm.h>

namespace renegade {
namespace chassis {

class Motor {
    public:
    Motor();
    ~Motor();
    bool set_throttle(int throttle_cmd);

    //private:
    //int FORWARD_PIN = 1;
    //int REVERSE_PIN = 2;
};

}
}