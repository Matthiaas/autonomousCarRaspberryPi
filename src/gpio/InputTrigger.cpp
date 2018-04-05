#include "include/InputTrigger.h"


InputTrigger::InputTrigger(int pin, void(*f)()) {

	if (wiringPiISR(pin, INT_EDGE_FALLING, f) < 0) {
		std::cout <<("14CORE | Obstacle Avoidance Sensor Test \n");
		std::cout <<("WARNING: Unable to setup ISR\n") ;
		return;
	}
}
