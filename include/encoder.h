#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

#define PI 3.14159265358979323846

#define LEFT_ENC_A 1
#define LEFT_ENC_B 3

#define RIGHT_ENC_A 19
#define RIGHT_ENC_B 5

#define TICKS_PER_REV 715

#define WHEEL_DIAMETER 3.2

#define WHEEL_CIRCUMFERENCE (PI*WHEEL_DIAMETER)

extern volatile long left_ticks;
extern volatile long right_ticks;

void encoder_setup();

float LeftWheelTravel();
float RightWheelTravel();
float GetDistanceTraveled();

float GetLeftWheelSpeed();
float GetRightWheelSpeed();
float GetAverageSpeed();

#endif // ENCODER_H