#ifndef SENSOR_CONTROL_H
#define SENSOR_CONTROL_H

#include "sensor.h"

#define OBSTACLE_THRESHOLD_MM 30 // 3cm

// True if the front sensor sees an obstacle within OBSTACLE_THRESHOLD_MM.
bool obstacle_ahead(const sensor_reading_t *reading);

#endif // SENSOR_CONTROL_H
