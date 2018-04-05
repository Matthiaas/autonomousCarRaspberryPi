#include "include/Motor.h"



Motor::Motor(int on , int direction , int p){
    this-> a = on;
    this->b = direction;
    this->p = p;
    pinMode (a, OUTPUT) ;
    pinMode (b, OUTPUT) ;
    pinMode (p, OUTPUT) ;

    softPwmCreate(p,0,100);

}


void Motor::setSpeed(int s){
    softPwmWrite(p, s); 
}

void Motor::setDirection(int direction){
    digitalWrite(b , direction);
}

void Motor::start(){
    digitalWrite(a , HIGH);
}

void Motor::stop(){
    digitalWrite(a , LOW);
    digitalWrite(b , LOW);
}



