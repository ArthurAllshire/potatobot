#include "Chassis.h"
#include "../RobotMap.h"

#include <Commands/DriveFromJoystick.h>

Chassis::Chassis() : Subsystem("Chassis")
{
    motors[0] = new CANTalon(MOTOR_A_ID);
    motors[1] = new CANTalon(MOTOR_B_ID);
    motors[2] = new CANTalon(MOTOR_C_ID);
    motors[3] = new CANTalon(MOTOR_D_ID);
}

void Chassis::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    SetDefaultCommand(new DriveFromJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::Drive(double vX, double vZ, double throttle) {
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
        motors[x]->Set(motor_values[x]);
    }
}
