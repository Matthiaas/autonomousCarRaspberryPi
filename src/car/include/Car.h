#ifndef CAR_H_
#define CAR_H_

#define PIN_MOTOR_PWM 12
#define PIN_MOTOR_ON 14
#define PIN_MOTOR_CHANGE 13

#define PIN_CHANGEDIR_CAR 1
#define PIN_STEER_CAR 2

#define PIN_SONAR_TRIGGER_CAR 3
#define PIN_SONAR_ECHO_CAR 4


#define PIN_LIGHT_FRONT 0

#define minInt(a,b) ((a<b) ? a:b)
#define maxInt(a,b) ((a<b) ? b:a)

#define ON 1
#define OFF 0

#include "gpio/include/OutPin.h"
#include "gpio/include/Sonar.h"
#include "gpio/include/Motor.h"

#include <thread>





class Car {
public:
    Car();
    ~Car();
    void forward();
    void backward();
    void setSpeed(int s);
    
    void start();
    void stop();


    void steerLeft();
    void steerRight();
    void steerStraight();
    void resetAll();

    void stopCruiseControl();
    void startCruiseControl(int maxSpeed);
    void startCruiseControl();

    void setLight(int f);
    

private:
	OutPin changeDir;
    OutPin steer;

    OutPin lightFront;
    bool lightOn = false;


    Sonar sonar;
    Motor motor;

    int currentSpeed = 0;
    int currentAbsoluteSpeed = 0;
    bool isForward = true;

    bool cruiseControlActive = false;
    std::thread *cruiseThread;
    void cruiseControl(int maxSpeed);
};


#endif /* CLIENT_H_ */