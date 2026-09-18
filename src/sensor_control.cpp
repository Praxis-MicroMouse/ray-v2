#include "sensor_control.h"

bool obstacle_ahead(const sensor_reading_t *reading)
{
    return reading->front_mm <= OBSTACLE_THRESHOLD_MM;
}
