#ifndef MOTOR_H
#define MOTOR_H

#define PWMA  4
#define PWMB  14

#define AIN1  33
#define AIN2  32

#define STDBY 25

#define BIN1  26
#define BIN2  27

void motor_setup();

void left_motor(int speed);
void right_motor(int speed);

void drive(int left_speed, int right_speed);
void stop_motors();

#endif