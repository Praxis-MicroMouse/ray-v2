#ifndef DRIVE_CONTROL_H
#define DRIVE_CONTROL_H

#include "pid.h"

typedef struct
{
    pid_ctrl_t straight_pid; // corrects left/right wheel-travel drift
} drive_control_t;

void drive_control_init(drive_control_t *ctrl);

// Drives both motors at base_speed, nudging left/right power apart to
// cancel out any difference in wheel travel (keeps the mouse driving
// straight). Call once per control loop iteration with the loop's dt
// in seconds.
void drive_straight(drive_control_t *ctrl, int base_speed, float dt);

#endif // DRIVE_CONTROL_H
