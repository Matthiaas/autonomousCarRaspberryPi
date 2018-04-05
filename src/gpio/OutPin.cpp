#include "include/OutPin.h"

OutPin::OutPin(int p){
    pin = p;
    pinMode (pin, OUTPUT) ;
}


void OutPin::setHigh(){
    digitalWrite (pin, HIGH) ;
}

void OutPin::setLow(){
    digitalWrite (pin, LOW) ;   
}
  
void OutPin::set(int value){
    digitalWrite (pin, value) ;
}
