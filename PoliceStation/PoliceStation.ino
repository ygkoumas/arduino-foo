int switchState = 13;
int k = 3;
int l = 1;
const float pi = 3.14;
float o;

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
    if (k == 0) {l = 1;}
    if (k == 100) {l = -1;}
    if (k < 50) {
      digitalWrite(3, HIGH);
    }
    else {
      digitalWrite(3, LOW);
    }
    k+=l;
  }
  else {
    digitalWrite(3, LOW);
    k = 4;
    l = 1;

    for (int i = 0; i<20; i++) {
      for (int i=0; i<2; i++) {
        digitalWrite(k, HIGH);
        siren(20);

        digitalWrite(k,LOW);
        siren(20);
      }
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);

      if (k == 4) {l = 1;}
      if (k == 5) {l = -1;}
      k+=l;
    }
    noTone(8);
  }
}


void siren(int duration) {
  for (int i = 0; i<duration; i++) {
    o++;
    tone(8, 2000+600*sin(o/100 * pi));
    Serial.println(sin(o/100 * pi));
    delay(8);
  }
}
