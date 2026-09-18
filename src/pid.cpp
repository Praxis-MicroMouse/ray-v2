#include "pid.h"

void pid_init(pid_ctrl_t *pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid_reset(pid);
}

void pid_reset(pid_ctrl_t *pid)
{
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
}

float pid_update(pid_ctrl_t *pid, float setpoint, float measured, float dt)
{
    float error = setpoint - measured;

    pid->integral += error * dt;
    float derivative = (dt > 0.0f) ? (error - pid->prev_error) / dt : 0.0f;
    pid->prev_error = error;

    return pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
}
