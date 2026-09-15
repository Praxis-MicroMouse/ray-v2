#ifndef BATTERY_H
#define BATTERY_H

#define BATTERY_PIN 34

#define R1 15000.0
#define R2 10000.0

void battery_setup();
float battery_voltage();

#endif