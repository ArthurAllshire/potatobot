#include "DriveForTime.h"

DriveForTime::DriveForTime(int seconds): Command("DriveForTime")
{
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(chassis);
    this->seconds_to_drive = seconds;
}

// Called just before this Command runs the first time
void DriveForTime::Initialize()
{
    time(&start_time);
    Potatobot::chassis->Drive(1.0,0.0,1.0); // drive forward at full speed
}

// Called repeatedly when this Command is scheduled to run
void DriveForTime::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForTime::IsFinished()
{
    if(difftime(time(NULL), start_time) >= this->seconds_to_drive) {
        return true;
    }
    return false;
}

// Called once after isFinished returns true
void DriveForTime::End()
{
    Potatobot::chassis->Drive(0.0,0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForTime::Interrupted()
{

}
