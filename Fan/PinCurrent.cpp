#include <Arduino.h>
#include "PinCurrent.h"

PinCurrent::PinCurrent(int pin, int current)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, current);
  _pin = pin;
  _current = current;
}

void PinCurrent::onoff()
{
  if (_current == 0) {
    _current=1;
    delay(500);
    digitalWrite(_pin, 1);
  }
  else {
    _current=0;
    delay(500);
    digitalWrite(_pin, 0);
  }

}

