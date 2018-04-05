#include "include/Car.h"

#include <iostream>

Car::~Car(){
}
Car::Car()
    :changeDir(PIN_CHANGEDIR_CAR)
    ,steer(PIN_STEER_CAR)
    ,sonar(PIN_SONAR_TRIGGER_CAR , PIN_SONAR_ECHO_CAR)
    ,motor(PIN_MOTOR_ON,PIN_MOTOR_CHANGE , PIN_MOTOR_PWM)
    ,lightFront(PIN_LIGHT_FRONT){

}
    
 void Car::setLight(int f){
        lightFront.set(f);
    }

void Car::forward(){
    motor.setDirection(DIR_FORWARD);
    isForward = true;
    setSpeed(currentSpeed);
}
void Car::backward(){
    motor.setDirection(DIR_BACKWARD);
    isForward = false;
    setSpeed(currentSpeed);
}

void Car::start(){
    motor.start();
}
void Car::stop(){
    resetAll();
}


void Car::setSpeed(int s){
    currentAbsoluteSpeed = s;
    if(isForward){
        currentSpeed = s;
    }   
    else{
        currentSpeed = 100 -s;
    }
    motor.setSpeed(currentSpeed);
}


void Car::steerLeft(){
    steer.setHigh();
    changeDir.setLow();
}
void Car::steerStraight(){
    steer.setLow();
}
void Car::steerRight(){
    steer.setHigh();
    changeDir.setHigh();
}
void Car::resetAll(){
    forward();
    motor.stop();
    changeDir.setLow();
    steer.setLow();
}



void Car::stopCruiseControl(){
    cruiseControlActive = false;
    cruiseThread->join();
    delete cruiseThread;
    forward();
    lightFront.setLow();
    motor.stop();
}

void Car::startCruiseControl(){
    startCruiseControl(100);
}

void Car::startCruiseControl(int maxSpeed){
    forward();
    lightFront.setHigh();
    cruiseControlActive = true;
    cruiseThread = new std::thread(&Car::cruiseControl , this ,minInt(maxSpeed , 100) );
}

void Car::cruiseControl(int maxSpeed){
    int lastdis  = 0;
    bool stop = false;
    while(cruiseControlActive){
        double dis = sonar.distance(30000);

        if((dis < 30  && currentAbsoluteSpeed != 0) ){ // || (  dis < 60 &&  lastdis  > dis + 5 ) 
            if(lastdis>dis && !stop){
                backward();
                setSpeed(100);
            }else{
                stop = true;
                setSpeed(0);
            }

           
        }else if (dis > 30 ){
            stop = false;
            int s = minInt(maxSpeed, maxInt(30 , dis/2));
            
            forward();
            setSpeed(s);
        }
        delay(100);
        lastdis = dis;
    }
}