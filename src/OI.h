#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick* joystick;
public:
    OI();
    double GetX(); // returns X axis of joystick (forwards relative to the robot) +/-1
    double GetY(); // returns Y axis of joystick (left relative to the robot) +/-1
    double GetZ(); // returns yaw of joystick, mapping to the robots Z axis(upwards relative to the robot) +/-1
    double GetThrottle(); // returns throttle of joystick, 0 - +1
};

#endif
