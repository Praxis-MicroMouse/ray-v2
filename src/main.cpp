#include <Arduino.h>
#include "sensor.h"
#include "sensor_control.h"
#include "encoder.h"
#include "motor.h"
#include "imu.h"

#define RUN_DISTANCE_CM 200.0f
#define FULL_SPEED 255

static bool s_imu_ok = false;

void setup()
{
    Serial.begin(115200);
    sensor_init();
    encoder_setup();
    motor_setup();

    s_imu_ok = imu_init();
    if (!s_imu_ok)
        Serial.println("[IMU] init failed, continuing without it");

    drive(FULL_SPEED, FULL_SPEED);
    while (GetDistanceTraveled() < RUN_DISTANCE_CM)
    {
        sensor_reading_t reading;
        sensor_read_all(&reading);
        if (obstacle_ahead(&reading))
        {
            Serial.println("[RUN] obstacle ahead, braking");
            break;
        }
        delay(1);
    }
    motor_stop();
}

void loop()
{
    sensor_reading_t reading;
    sensor_read_all(&reading);

    if (s_imu_ok)
    {
        imu_data_t imu;
        imu_read(&imu);
        Serial.printf("front=%u "
                      "left=%u "
                      "right=%u | "
                      "ax=%.2f ay=%.2f az=%.2f "
                      "gx=%.2f gy=%.2f gz=%.2f\n",
                      reading.front_mm, reading.left_mm, reading.right_mm,
                      imu.ax, imu.ay, imu.az, imu.gx, imu.gy, imu.gz);
    }
    else
    {
        Serial.printf("front=%u "
                      "left=%u "
                      "right=%u\n",
                      reading.front_mm, reading.left_mm, reading.right_mm);
    }

    delay(50);
}