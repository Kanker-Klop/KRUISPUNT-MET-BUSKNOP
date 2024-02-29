#include <Arduino.h>
unsigned long flakk = 0;
int pinsetup = 3;
void setup() {
  for (pinsetup = 3; pinsetup<9; pinsetup++) {
    pinMode(pinsetup, OUTPUT);
  }
  pinMode(2, INPUT_PULLUP);
  for (pinsetup = 3; pinsetup<9; pinsetup++) {
    digitalWrite(pinsetup, LOW);
  }
}
int hetlichtdataanis = 3;
int voriglicht = 8;
int roodlicht = 8;
int interval = 0;
int busvoorrangknop = 1;
void loop() {
  for (hetlichtdataanis = 3; hetlichtdataanis<9; hetlichtdataanis++) {
    switch (hetlichtdataanis) {
      case 3:
        voriglicht = 5;
        interval = 8000;
        roodlicht = 8;
        break;    
      case 4:
        voriglicht = hetlichtdataanis-1;
        interval = 2000;
        roodlicht = 8;
        break;
      case 5:
        voriglicht = hetlichtdataanis-1;
        hetlichtdataanis = 6;
        roodlicht = 5;
        interval = 8000;
        digitalWrite(8, LOW);
        break;
      case 6:
        voriglicht = hetlichtdataanis-1;
        interval = 8000;
        roodlicht = 5;
        break;
      case 7:
        voriglicht = hetlichtdataanis-1;
        interval = 2000;
        roodlicht = 5;
        break;
      case 8:
        voriglicht = hetlichtdataanis-1;
        hetlichtdataanis = 3;
        roodlicht = 8;
        interval = 8000;
        digitalWrite(5, LOW);
        break;
    }
    flakk = millis();
    while (millis() < (flakk + interval)) {
      busvoorrangknop = digitalRead(2);
    if ((busvoorrangknop == 0) && digitalRead(6)) {
      flakk = millis();
      hetlichtdataanis = 7;
      voriglicht = 6;
      interval = 2000;
      roodlicht = 5;
    }
      digitalWrite(voriglicht, LOW);
      digitalWrite(roodlicht, HIGH);
      digitalWrite(hetlichtdataanis, HIGH);
    }
  }
}