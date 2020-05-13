#include <ros/ros.h>
#include <chassis/chassis_msg.h>
#include <serial.h>
#include <sstream>


renegade::common::SerialInterface chassis_state("/dev/ttyUSB0");

int main(int argc, char** argv) {

    ros::init(argc, argv, "vehicle_state_provider");
    ros::NodeHandle vehicle_state;
    
    ros::Publisher vehicle_state_pub = vehicle_state.advertise<chassis::chassis_msg>("/renegade/chassis", 5);

    std::string line;

    while(ros::ok()) {
        if(chassis_state.Read(&line)){
            chassis::chassis_msg msg;
            std::vector <double> state;
            state = chassis_state.Parse(line);
            msg.velocity = state[0];
            vehicle_state_pub.publish(msg);
        }
    }

    return 0;
}
