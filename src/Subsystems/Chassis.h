#ifndef CHASSIS_H
#define CHASSIS_H

#include "WPILib.h"

class Chassis: public Subsystem
{
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    CANTalon motor_a;
    CANTalon motor_b;
    CANTalon motor_c;
    CANTalon motor_d;
    CANTalon motors[4];
public:
    Chassis();
    void InitDefaultCommand();
    void Drive(double vX, double vZ, double throttle);
};

#endif
