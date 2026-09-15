#include "battery.h"

#include <Arduino.h>

void battery_setup()
{
    analogReadResolution(12);
}

float battery_voltage()
{
    int raw = analogRead(BATTERY_PIN);

    float voltage = raw * 3.3 / 4095.0;

    return voltage * ((R1 + R2) / R2);
}