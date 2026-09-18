#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// TB6612FNG pins
#define AIN1 25
#define AIN2 26
#define PWMA 27

#define BIN1 32
#define BIN2 33
#define PWMB 14

#define STBY 13

void motor_setup();
void motor_left(int speed);
void motor_right(int speed);
void drive(int left, int right);
void motor_stop();

#endif