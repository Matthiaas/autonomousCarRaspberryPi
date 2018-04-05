#ifndef GYRO_H
#define GYRO_H

class Gyro {
public:
	Gyro();
	float getX();
	float getY();
	float getZ();
private:
	int fd;
};

#endif