#include "drive_control.h"

#include "encoder.h"
#include "motor.h"

void drive_control_init(drive_control_t *ctrl)
{
    pid_init(&ctrl->straight_pid, 2.0f, 0.0f, 0.1f);
}

void drive_straight(drive_control_t *ctrl, int base_speed, float dt)
{
    float travel_diff = LeftWheelTravel() - RightWheelTravel();
    float correction = pid_update(&ctrl->straight_pid, 0.0f, travel_diff, dt);

    motor_left(base_speed - (int)correction);
    motor_right(base_speed + (int)correction);
}
