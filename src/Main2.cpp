#include <stdio.h>
#include <iostream>
#include <wiringPi.h>


#include "car/include/Car.h"

#include "gpio/include/Motor.h"
#include "gpio/include/InputTrigger.h"

//#include "gpio/include/Sonar.h"
//#include "gpio/include/OutPin.h"

//#include "network/Client.h"
//#include "network/Server.h"
//using namespace Network;
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


int main(void)
{
	std::cout << "Ok" << std::endl;
	if (wiringPiSetup() == -1) { // Wiringpi initialization failed print error
		printf(" Wiringpi initialization failed!\n");
		return 1;
	}

	

//	InputTrigger it(5 ,da );

	Car car;
	car.start();
	car.cruiseControl();
//	car = &care;
	

	//InputTrigger it2(5 , da2 , false);



	
//	Car car;
//	car.start();


	delay(10000);


/*	
	Motor m(13,14,12);
	
	m.setDirection(1);
		std::cout << "Ok" << std::endl;
	delay(1000);
	m.setSpeed(10);
	delay(1000);
	m.setSpeed(50);
	delay(1000);
	m.setSpeed(100);
	delay(3000);
	m.stop();

	
	Car car;
	car.cruiseControl();
	

	


	OutPin forward(0);
	OutPin changeDir(1);
	OutPin steer(2);

	forward.setLow();
	changeDir.setLow();
	steer.setLow();


	steer.setHigh();
	delay(1000);	
	changeDir.setHigh();
	delay(1000);
	changeDir.setLow();	
	delay(1000);
	steer.setLow();
	



	Server s(10555);
	s.openServerSocket();
	Client c(s.acceptNext());
	string str = string("Welcome to the car controllong service!\n\t0 to stop\n\t1 for gas\n\t2 for left\n\t3 for straigt\n\t4 for rigth\n\tPlease send data as byte!");
	c.writeString(str);


	Sonar sonar(3,4);
//cout << sonar.distance(30000) << endl;
	while(true){
		
		int res = c.readByte();
		switch(res){
			case 0:
				forward.setLow();
				
			break;
			case 1:
				forward.setHigh();
			break;
			case 2:
				steer.setHigh();
				changeDir.setLow();
			break;
			case 3:
				steer.setLow();
			break;
			case 4:
				steer.setHigh();
				changeDir.setHigh();
			break;
		}
	}

	return 0;
}
  */