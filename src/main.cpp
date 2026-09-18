#include <Arduino.h>

#include "sensor.h"
#include "encoder.h"
#include "motor.h"
#include "udp.h"

void setup()
{
    Serial.begin(115200);

    sensor_init();
    encoder_setup();
    motor_setup();
    udp_init();

    drive(255, 255);
    while (GetDistanceTraveled() < 200.0f)
    {
        delay(1);
    }
    motor_stop();
    
}

void loop()
{
    sensor_reading_t reading;
    sensor_read_all(&reading);

    Serial.printf(
        "front=%u left=%u right=%u | L=%ld R=%ld | D=%.2f cm\n",
        reading.front_mm,
        reading.left_mm,
        reading.right_mm,
        left_ticks,
        right_ticks,
        GetDistanceTraveled()
    );

    delay(50);

    udp_send("Hello");
    delay(1000);
}
