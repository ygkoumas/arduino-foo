#include <Arduino.h>
#include "Lib.h"

const float pi = 3.14;

float siren(int duration, float o) {
  for (int i = 0; i<duration; i++) {
    o++;
    tone(8, 2000+600*sin(o/100 * pi));
    Serial.println(sin(o/100 * pi));
    delay(8);
  }
  return o;
}

