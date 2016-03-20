#include <Arduino.h>
#include "Lib.h"

const float pi = 3.14;

float sgn(float num) {
  if (num>=0)return 1;
  return -1;
}

void siren(int duration) {
  static float o = 0;
  for (int i = 0; i<duration; i++) {
    o++;

    float harmonic = sin(o/100 * pi);
    float toneFrequency = 2000+500 * pow(abs(harmonic), 0.01) * sgn(harmonic);
    tone(8, toneFrequency);
    Serial.println(sin(o/100 * pi));
    delay(8);
  }
}

void simpleSiren(int duration) {
  static int o = 0;
  float toneFrequency;
  o += duration;

  if (o%200 < 100) {
    toneFrequency = 2500;
  }
  else {
    toneFrequency = 1500;
  }

  tone(8, toneFrequency);
  delay(10* duration);
}
