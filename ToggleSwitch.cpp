#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch() {
}

void ToggleSwitch::setup(int switchPin) {
  Serial.println("ToggleSwitch.setup");
  this->switchPin = switchPin;
  this->isChanged = false;
  pinMode(this->switchPin, INPUT);
}


void ToggleSwitch::loop() {
  int newState = analogRead(this->switchPin) > 500 ? HIGH : LOW;
  if (newState != this->state) {
    this->state = newState;
    this->isChanged = true;
    Serial.println("Toggle Switch Change");
    Serial.println(newState);
  } else {
    this->isChanged = false;
  }
}
