#include <Arduino.h>

#include "sensor.h"
#include "encoder.h"
#include "bluetooth.h"
#include "battery.h"
#include "motor.h"

void setup()
{
    Serial.begin(115200);

    sensor_init();
    encoder_setup();
    battery_setup();
    motor_setup();

    bluetooth_init();

    // Spin both motors forward
    drive(150, 150);
}

void loop()
{
    sensor_reading_t reading;
    sensor_read_all(&reading);

    bluetooth_handle();

    float battery = battery_voltage();

    Serial.printf(
        "front=%u left=%u right=%u | L=%ld R=%ld | D=%.2f cm | V=%.2f V\n",
        reading.front_mm,
        reading.left_mm,
        reading.right_mm,
        left_ticks,
        right_ticks,
        GetDistanceTraveled(),
        battery
    );

    char data[120];

    snprintf(
        data,
        sizeof(data),
        "S %u %u %u E %ld %ld D %.2f V %.2f",
        reading.front_mm,
        reading.left_mm,
        reading.right_mm,
        left_ticks,
        right_ticks,
        GetDistanceTraveled(),
        battery
    );

    bluetooth_send(data);

    delay(50);
}
