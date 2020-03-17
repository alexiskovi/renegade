#include <serial.h>
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "serial_read_test");
    ros::NodeHandle srt;
    ros::Rate loop_rate(100);
    renegade::common::SerialInterface si("/dev/ttyUSB0");

    while(ros::ok()) {
        std::string msg;
        if(!si.Read(&msg)) std::cout << "Not recieved any messages" << std::endl;
        else std::cout << msg << std::endl;
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}