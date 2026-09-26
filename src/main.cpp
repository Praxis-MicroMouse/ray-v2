#include <Arduino.h>
#include "sensor.h"
#include "encoder.h"

void setup()
{
    Serial.begin(115200);

    encoder_setup();
    sensor_init();

    Serial.println("Sensor initialized.");
}

void loop()
{
    sensor_reading_t reading;

    sensor_read_all(&reading);

    // Serial.printf(
    //     "Front: %u mm | Right: %u mm | Left: %u mm\n",
    //     reading.front_mm,
    //     reading.right_mm,
    //     reading.left_mm
    // );

    Serial.printf(
        "Left ticks: %ld | Right ticks: %ld | Left dist: %.2f cm | Right dist: %.2f cm | Avg speed: %.2f cm/s\n",
        left_ticks,
        right_ticks,
        LeftWheelTravel(),
        RightWheelTravel(),
        GetAverageSpeed()
    );

    delay(100);
}