#include <Arduino.h>
#include "Lib.h"

const float pi = 3.14;

float sgn(float num) {
  if (num>=0)return 1;
  return -1;
}

float siren(int duration, float o) {
  for (int i = 0; i<duration; i++) {
    o++;

    float harmonic = sin(o/100 * pi);
    float toneFrequency = 2000+500 * pow(abs(harmonic), 0.01) * sgn(harmonic);
    tone(8, toneFrequency);
    Serial.println(sin(o/100 * pi));
    delay(8);
  }
  return o;
}

