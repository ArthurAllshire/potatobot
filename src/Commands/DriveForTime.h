#ifndef DRIVE_FOR_TIME_H
#define DRIVE_FOR_TIME_H

#include "WPILib.h"
#include <time.h>
#include <Potatobot.h>

class DriveForTime: public Command
{
public:
    DriveForTime(int seconds);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
private:
    time_t start_time;
    int seconds_to_drive;
};

#endif
