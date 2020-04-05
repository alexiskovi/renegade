#include <ublox.h>
#include <ros/ros.h>
#include <gps/gps_msg.h>


int main(int argc, char** argv) {

    ros::init(argc, argv, "gps");
    ros::NodeHandle gps;
    
    ros::Publisher gps_pub = gps.advertise<gps::gps_msg>("/renegade/gps", 5);

    renegade::gps::Ublox ublox;

    while(ros::ok()){
        gps::gps_msg msg;
        std::string line;
        if(ublox.GetNewLine(&line)){
            std::vector <double> parsed;
            parsed = ublox.Parse(line);
            
            //fill header
            
            msg.longitude = parsed[0];
            msg.latitude = parsed[1];
            msg.altitude = parsed[2];
            msg.velocity = parsed[3];
            msg.satellites_num = (int) parsed[4];

            gps_pub.publish(msg);
        }
        ros::spinOnce();
    }
    return 0;
}
