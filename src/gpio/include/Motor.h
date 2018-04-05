#ifndef MOTOR_H_


#define MOTOR_H_
#define DIR_FORWARD 0 
#define DIR_BACKWARD 1


#include <wiringPi.h>
#include <softPwm.h>


class Motor{
public:
    Motor(int a , int b, int p);
    void setSpeed(int s);
    void setDirection(int direction);
    void start();
    void stop();

private:
    int a , b, p;
};


#endif