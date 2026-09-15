#include "motor.h"

#include <Arduino.h>

#define PWM_FREQ 20000
#define PWM_RES  8

#define LEFT_CHANNEL  0
#define RIGHT_CHANNEL 1

void motor_setup()
{
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);

    pinMode(STDBY, OUTPUT);
    digitalWrite(STDBY, HIGH);

    ledcSetup(LEFT_CHANNEL, PWM_FREQ, PWM_RES);
    ledcSetup(RIGHT_CHANNEL, PWM_FREQ, PWM_RES);

    ledcAttachPin(PWMA, LEFT_CHANNEL);
    ledcAttachPin(PWMB, RIGHT_CHANNEL);

    stop_motors();
}

void left_motor(int speed)
{
    speed = constrain(speed, -255, 255);

    digitalWrite(AIN1, speed >= 0);
    digitalWrite(AIN2, speed < 0);

    ledcWrite(LEFT_CHANNEL, abs(speed));
}

void right_motor(int speed)
{
    speed = constrain(speed, -255, 255);

    digitalWrite(BIN1, speed >= 0);
    digitalWrite(BIN2, speed < 0);

    ledcWrite(RIGHT_CHANNEL, abs(speed));
}

void drive(int left_speed, int right_speed)
{
    left_motor(left_speed);
    right_motor(right_speed);
}

void stop_motors()
{
    ledcWrite(LEFT_CHANNEL, 0);
    ledcWrite(RIGHT_CHANNEL, 0);
}