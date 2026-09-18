#ifndef PID_H
#define PID_H

typedef struct
{
    float kp, ki, kd;

    float integral;
    float prev_error;
} pid_ctrl_t;

void pid_init(pid_ctrl_t *pid, float kp, float ki, float kd);
void pid_reset(pid_ctrl_t *pid);

// Runs one PID step and returns the control output.
float pid_update(pid_ctrl_t *pid, float setpoint, float measured, float dt);

#endif // PID_H
