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
  _current += 1;
  _current %= 2;
  delay(500);
  digitalWrite(_pin, _current);
}

