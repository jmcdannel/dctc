#include <Arduino.h>
#include "Throttle.h"

Throttle::Throttle() {
}

void Throttle::setup(int throttlePin, int speedPin) {
  Serial.println("Throttle.setup");
  this->throttlePin = throttlePin;
  this->speedPin = speedPin;
  pinMode(this->throttlePin, INPUT); 
  
}


void Throttle::loop() {
  int newSpeed = map(analogRead(this->throttlePin), 0, 1023, 0, 255);

  if (this->currentSpeed != newSpeed) { //speed is changed
    analogWrite(this->speedPin, newSpeed);
    this->currentSpeed = newSpeed;
  }
  
}
