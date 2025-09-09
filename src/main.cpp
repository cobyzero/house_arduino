#include <Arduino.h>

int pinSensor = 8;
int pinLed = 7;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinSensor, INPUT);
}

void loop() {
  int sensorValue = digitalRead(pinSensor);
  if (sensorValue == HIGH) {
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
  } else {
    digitalWrite(pinLed, LOW);
    delay(500);
  }
  delay(2000);
}
 