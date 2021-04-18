#include "Track.h"
#include <Pushbutton.h>

Track::Track(int buttonPin, int relayPin, int LEDPin)
      : button(buttonPin) {
  this->relayPin = relayPin;
  this->LEDPin = LEDPin;
  this->buttonPin = buttonPin;
  this->state = LOW;
}

void Track::setup() {  
  pinMode(this->relayPin, OUTPUT); 
  pinMode(this->LEDPin, OUTPUT);
  pinMode(this->buttonPin, INPUT);
}


void Track::loop() {
  
  if (button.getSingleDebouncedPress()) {
    Serial.println("track button pressed");
    this->state = !this->state == HIGH ? LOW : HIGH;
    digitalWrite(this->relayPin, this->state);
    digitalWrite(this->LEDPin, this->state);
  }
}
