#include "imu.h"

#include <Arduino.h>
#include <Wire.h>

#define MPU_WHO_AM_I 0x75
#define MPU_PWR_MGMT 0x6B
#define MPU_ACCEL_XOUT 0x3B
#define MPU_GYRO_XOUT 0x43

static uint8_t imu_type;

static int16_t read16(uint8_t reg)
{
    Wire.beginTransmission(IMU_ADDR);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(IMU_ADDR, (uint8_t)2);

    return (int16_t)((Wire.read() << 8) | Wire.read());
}

bool imu_init(void)
{
    // Wire is already brought up by sensor_init(), which must run first.
    Wire.beginTransmission(IMU_ADDR);
    if (Wire.endTransmission() != 0)
        return false;

    Wire.beginTransmission(IMU_ADDR);
    Wire.write(MPU_WHO_AM_I);
    Wire.endTransmission(false);

    Wire.requestFrom(IMU_ADDR, (uint8_t)1);

    if (!Wire.available())
        return false;

    imu_type = Wire.read();

    // MPU6050 = 0x68
    // MPU6500 = 0x70
    if (imu_type != 0x68 && imu_type != 0x70)
        return false;

    // Wake up
    Wire.beginTransmission(IMU_ADDR);
    Wire.write(MPU_PWR_MGMT);
    Wire.write(0x00);
    Wire.endTransmission();

    delay(100);

    return true;
}

bool imu_read(imu_data_t *out)
{
    if (!out)
        return false;

    int16_t ax = read16(MPU_ACCEL_XOUT);
    int16_t ay = read16(MPU_ACCEL_XOUT + 2);
    int16_t az = read16(MPU_ACCEL_XOUT + 4);

    int16_t gx = read16(MPU_GYRO_XOUT);
    int16_t gy = read16(MPU_GYRO_XOUT + 2);
    int16_t gz = read16(MPU_GYRO_XOUT + 4);

    // ±2g
    out->ax = ax / 16384.0f;
    out->ay = ay / 16384.0f;
    out->az = az / 16384.0f;

    // ±250 °/s
    out->gx = gx / 131.0f;
    out->gy = gy / 131.0f;
    out->gz = gz / 131.0f;

    return true;
}