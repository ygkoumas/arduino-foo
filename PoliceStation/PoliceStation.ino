#include "Lib.h"

int switchState = 13;
int k = 3;
int l = 1;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) {
    delay(10);
    if (k == 0) {
      digitalWrite(3, HIGH);
      l = 1;
    }
    else if (k == 100) {
      digitalWrite(3, LOW);
      l = -1;
    }
    k += l;
  }
  else {
    digitalWrite(3, LOW);
    k = 0;

    for (int i=0; i<20; i++) {
      for (int i=0; i<2; i++) {
        digitalWrite(4+k, HIGH);
        siren(25);

        digitalWrite(4+k,LOW);
        siren(25);
      }
      k += 1;
      k %= 2;
    }
    noTone(8);
  }
}

