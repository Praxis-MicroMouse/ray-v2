#ifndef IMU_H
#define IMU_H

#include <stdint.h>
#include <stdbool.h>

#define IMU_SDA 21
#define IMU_SCL 22

#define IMU_ADDR 0x68

typedef struct
{
    float ax;
    float ay;
    float az;

    float gx;
    float gy;
    float gz;
} imu_data_t;

bool imu_init(void);
bool imu_read(imu_data_t *out);

#endif // IMU_H