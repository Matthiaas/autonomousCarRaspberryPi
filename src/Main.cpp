#include <stdio.h>
#include <iostream>
#include <wiringPi.h>


#include "car/include/Car.h"

#include "gpio/include/Motor.h"
#include "gpio/include/InputTrigger.h"

//#include "gpio/include/Sonar.h"
//#include "gpio/include/OutPin.h"

#include "network/Client.h"
#include "network/Server.h"
using namespace Network;
using namespace std;
/*
int x = 0;
Car *car;
void da(){

	if ( digitalRead(5) == 1){
		car->setLigth(ON);
	}else{
		car->setLigth(OFF);
	}
	
}

  */
int main(void)
{
	std::cout << "Ok" << std::endl;
	if (wiringPiSetup() == -1) { // Wiringpi initialization failed print error
		printf(" Wiringpi initialization failed!\n");
		return 1;
	}

	

//	InputTrigger it(5 ,da );
/*
	Server s(10555);
	s.openServerSocket();
	Client c(s.acceptNext());
	string str = string("Welcome to the car controllong service!\n\t0 to stop\n\t1 for gas\n\t2 for left\n\t3 for straigt\n\t4 for rigth\n\tPlease send data as byte!");
	c.writeString(str);

*/
	Car car;
	car.start();
	car.startCruiseControl();

	delay(30000);	
//	car.forward();
/*
	while(true){

		
		int res = c.readByte();
		switch(res){
			case 0:
				car.setSpeed(0);

			break;
			case 1:
				car.setSpeed(100);
			break;
			case 2:
				car.steerLeft();
			break;
			case 3:
				car.steerStraight();
			break;
			case 4:
				car.steerRight();
			break;
		}
	}
*/
	return 0;
}
