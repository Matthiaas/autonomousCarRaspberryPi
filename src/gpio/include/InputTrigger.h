#ifndef INPUTTRIGGER_H_
#define INPUTTRIGGER_H_


#include <wiringPi.h>
#include <iostream>


class InputTrigger {
public:
	InputTrigger(int pin ,void(*f)() );
};

#endif