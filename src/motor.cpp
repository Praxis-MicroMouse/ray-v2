#include "motor.h"

void motor_setup()
{
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    pinMode(STBY, OUTPUT);

    digitalWrite(STBY, HIGH);
}

void motor_left(int speed)
{
    speed = constrain(speed, -255, 255);

    digitalWrite(AIN1, speed >= 0);
    digitalWrite(AIN2, speed < 0);

    analogWrite(PWMA, abs(speed));
}

void motor_right(int speed)
{
    speed = constrain(speed, -255, 255);

    digitalWrite(BIN1, speed >= 0);
    digitalWrite(BIN2, speed < 0);

    analogWrite(PWMB, abs(speed));
}

void drive(int left, int right)
{
    motor_left(left);
    motor_right(right);
}

void motor_stop()
{
    drive(0, 0);
}