#include "Cab.h"
#include "Throttle.h"
#include <Pushbutton.h>

Cab::Cab(int throttlePin, int switchPin, int powerPin, int brakePin, int speedPin, int fwdLedIndex, int revLedIndex)
      : button(switchPin) {
  this->throttlePin = throttlePin;
  this->switchPin = switchPin;
  this->powerPin = powerPin;
  this->brakePin = brakePin;
  this->speedPin = speedPin;
  this->fwdLedIndex = fwdLedIndex;
  this->revLedIndex = revLedIndex;
  this->currentDirection = HIGH;
  this->currentSpeed = 0;
}

void Cab::setup() {
  this->throttle.setup(this->throttlePin, this->speedPin);
  
  pinMode(this->powerPin, OUTPUT); 
  pinMode(this->brakePin, OUTPUT);
}


void Cab::loop() {
  this->throttle.loop();
  
  if (button.getSingleDebouncedPress()) {
    Serial.println("button pressed");
    this->currentDirection = this->currentDirection == HIGH ? LOW : HIGH;
    digitalWrite(this->powerPin, this->currentDirection);
    digitalWrite(this->brakePin, LOW); // release brake
    digitalWrite(this->fwdLedIndex, this->currentDirection);
    digitalWrite(this->revLedIndex, !this->currentDirection);
  }
}
