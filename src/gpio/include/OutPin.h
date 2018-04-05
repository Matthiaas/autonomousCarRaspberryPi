#ifndef OUTPIN_H_
#define OUTPIN_H_

#include <wiringPi.h>

class OutPin{
private:
    int pin;
public:
    OutPin(int p);
    void setHigh();
    void setLow();
    void set(int hl);
};

#endif