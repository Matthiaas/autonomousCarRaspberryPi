#ifndef LED_H
#define LED_H

class Led {
public:
	Led(int a , int b , int c);
	void switchColor();
private:
	int map(int x, int in_min, int in_max, int out_min, int out_max);
	void ledColorSet(int color);
	int color;
	int LedPinRed;
	int LedPinGreen;
	int LedPinBlue;
};

#endif