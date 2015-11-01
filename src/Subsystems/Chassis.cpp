#include "Chassis.h"
#include "../RobotMap.h"

Chassis::Chassis() : Subsystem("Chassis")
{
    this->motor_a = new CANTalon(MOTOR_A_ID);
    this->motor_b = new CANTalon(MOTOR_B_ID);
    this->motor_c = new CANTalon(MOTOR_C_ID);
    this->motor_d = new CANTalon(MOTOR_D_ID);
    this->motors={motor_a, motor_b, motor_c, motor_d};
}

void Chassis::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    SetDefaultCommand(new OmniDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive(double vX, double vZ, double throttle) {
    double motor_values[4] = {0.0, 0.0, 0.0, 0.0}; // A, B, C, D

    motor_values[0] = vX * 1.0 - vZ * 1.0;
    motor_values[1] = vX * 1.0 - vZ * 1.0;
    motor_values[2] = vX * -1.0 - vZ * -1.0;
    motor_values[4] = vX * -1.0 - vZ * -1.0;

    double max=1.0;
    for(int x = 0; x<4; x++) {
        if(motor_values[x] > max)
            max = motor_values[x];
    }

    for(int x = 0; x<4; x++){
        motor_values[x]/=max;
        this->motors[x]->Set(motor_values[x])
    }
}
