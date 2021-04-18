#include "Effect.h"
#include <Pushbutton.h>

Effect::Effect(int inputPin, int outputPin)
      : button(inputPin) {
  this->inputPin = inputPin;
  this->outputPin = outputPin;
  this->state = LOW;
}

void Effect::setup() {  
  pinMode(this->outputPin, OUTPUT);
  pinMode(this->inputPin, INPUT);
}


void Effect::loop() {
  
  if (button.getSingleDebouncedPress()) {
    Serial.println("effect button pressed");
    this->state = !this->state == HIGH ? LOW : HIGH;
    digitalWrite(this->outputPin, this->state);
  }
}
