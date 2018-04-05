#include "include/Led.h"

#include <stdio.h>
#include <iostream>
#include <softPwm.h>



const int colors[] = { 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF, 0xFFFFFF, 0x9400D3 };

using namespace std;





Led::Led(int r , int g , int b) {
	LedPinRed = r;
	LedPinGreen = g;
	LedPinBlue = b;
	cout << "LED running" << endl;
	softPwmCreate(LedPinRed, 0, 100);  //create a soft pwm, original duty cycle is 0Hz, range is 0~100
	softPwmCreate(LedPinGreen, 0, 100);
	softPwmCreate(LedPinBlue, 0, 100);
	color = 0;
}

	
void Led::switchColor() {
	ledColorSet(colors[color]);
	color++;
	if (color == 8) {
		color = 0;
	}
}
	



int Led::map(int x, int in_min, int in_max, int out_min, int out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void Led::ledColorSet(int color)        //set color, for example: 0xde3f47
{
	int r_val, g_val, b_val;

	r_val = (color & 0xFF0000) >> 16;  //get red value
	g_val = (color & 0x00FF00) >> 8;   //get green value
	b_val = (color & 0x0000FF) >> 0;   //get blue value

	r_val = map(r_val, 0, 255, 0, 100);    //change a num(0~255) to 0~100
	g_val = map(g_val, 0, 255, 0, 100);
	b_val = map(b_val, 0, 255, 0, 100);

	softPwmWrite(LedPinRed, 100 - r_val);  //change duty cycle
	softPwmWrite(LedPinGreen, 100 - g_val);
	softPwmWrite(LedPinBlue, 100 - b_val);
}

	

