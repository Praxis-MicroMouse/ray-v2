#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// TB6612FNG pins
#define AIN1 25
#define AIN2 33
#define PWMA 32

#define BIN1 14
#define BIN2 27
#define PWMB 12

#define STBY 26

void motor_setup();
void motor_left(int speed);
void motor_right(int speed);
void drive(int left, int right);
void motor_stop();

#endif