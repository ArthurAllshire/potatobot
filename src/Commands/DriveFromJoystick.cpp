#include "DriveFromJoystick.h"

#include <Potatobot.h>

DriveFromJoystick::DriveFromJoystick(): Command("DriveFromJoystick")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    Requires(Potatobot::chassis);
}

// Called just before this Command runs the first time
void DriveFromJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveFromJoystick::Execute()
{
    double vX = Potatobot::oi->GetX();
    double vZ = Potatobot::oi->GetZ();
    double throttle = Potatobot::oi->GetThrottle();
    Potatobot::chassis->Drive(vX, vZ, throttle);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromJoystick::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void DriveFromJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromJoystick::Interrupted()
{

}
