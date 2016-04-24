#include "PinCurrent.h"

PinCurrent fanPinCurrent(7, 0);

int switchState = 13;

void setup() {
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == HIGH) {
    fanPinCurrent.onoff();
  }
}

