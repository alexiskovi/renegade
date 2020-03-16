#include "ros/ros.h"

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