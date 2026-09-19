#include <Arduino.h>
#include "sensor.h"
#include "encoder.h"
#include "udp.h"

void setup()
{
    Serial.begin(115200);
    encoder_setup();
    sensor_init();
    udp_init();
}

void loop()
{
    sensor_reading_t reading;
    sensor_read_all(&reading);

    char msg[128];
    snprintf(msg, sizeof(msg),
             "front=%u right=%u left=%u mm | ticks L=%ld R=%ld | travel L=%.2f R=%.2f avg=%.2f cm",
             reading.front_mm, reading.right_mm, reading.left_mm,
             left_ticks, right_ticks,
             LeftWheelTravel(), RightWheelTravel(), GetDistanceTraveled());

    Serial.println(msg);
    udp_send(msg);
    delay(100);
}
