#ifndef IMU_H
#define IMU_H

#include <stdint.h>
#include <stdbool.h>

// MPU6050 shares the same physical I2C bus as the ToF sensors.
#define IMU_SDA 21
#define IMU_SCL 22

#define IMU_ADDR ((uint8_t)0x68)

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