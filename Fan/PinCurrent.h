#ifndef PinCurrent_h
#define PinCurrent_h

#include <Arduino.h>

class PinCurrent
{
  public:
    PinCurrent(int pin, int current);
    void onoff();
  private:
    int _pin;
    int _current;
};

#endif
