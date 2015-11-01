#include "OI.h"

OI::OI()
{
    joystick = new Joystick(0);
    // Process operator interface input here.
}

double OI::GetX() {
    return -joystick->GetY();
}


double OI::GetY() {
    return -joystick->GetX();
}


double OI::GetZ() {
    return joystick->GetTwist();
}


double OI::GetThrottle() {
    return joystick->GetThrottle();
}
