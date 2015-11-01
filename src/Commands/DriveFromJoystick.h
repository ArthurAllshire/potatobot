#ifndef DRIVE_FROM_JOYSTICK_H
#define DRIVE_FROM_JOYSTICK_H

#include "WPILib.h"

class DriveFromJoystick: public Command
{
public:
    DriveFromJoystick();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
};

#endif
