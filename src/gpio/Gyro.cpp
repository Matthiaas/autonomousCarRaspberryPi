#include "include/Gyro.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define MPU6050_GYRO_XOUT_H        0x3B   // R
#define MPU6050_GYRO_YOUT_H        0x3D   // R
#define MPU6050_GYRO_ZOUT_H        0x3F   // R

#define MPU6050_PWR_MGMT_1         0x6B   // R/W
#define MPU6050_I2C_ADDRESS        0x68   // I2C


Gyro::Gyro() {

	fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
	if (fd == -1)
		return;

	wiringPiI2CReadReg8(fd, MPU6050_PWR_MGMT_1);
	wiringPiI2CWriteReg16(fd, MPU6050_PWR_MGMT_1, 0);

	

}

float Gyro::getX() {
	return wiringPiI2CReadReg8(fd, MPU6050_GYRO_XOUT_H);
}

float Gyro::getZ() {
	return wiringPiI2CReadReg8(fd, MPU6050_GYRO_ZOUT_H);
}

float Gyro::getY() {
	return wiringPiI2CReadReg8(fd, MPU6050_GYRO_YOUT_H);
}
