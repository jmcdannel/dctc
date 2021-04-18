#include "Turnout.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Pushbutton.h>

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

Turnout::Turnout(int index, int straight, int divergent, int buttonPin, int straigtLedIndex, int divergentLedIndex)
      : button(buttonPin) {
  this->index = index;
  this->straight = straight;
  this->divergent = divergent;
  this->buttonPin = buttonPin;
  this->straigtLedIndex = straigtLedIndex;
  this->divergentLedIndex = divergentLedIndex;
  
}

void Turnout::setup(Adafruit_PWMServoDriver pwm) {
  Serial.println("Turnout.setup");
  this->pwm = pwm;
  this->current = this->straight;
}


void Turnout::loop() {
  if (button.getSingleDebouncedPress()) {
    Serial.println("button pressed");
    if (this->current == this->straight) {
      this->setDivergent();
    } else {
      this->setStraight();
    }
  }
}

int Turnout::pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}

void Turnout::setStraight() {
  this->pwm.setPWM(this->index, 0, pulseWidth(this->straight));
  digitalWrite(this->straigtLedIndex, HIGH);
  digitalWrite(this->divergentLedIndex, LOW);
  this->current = this->straight;
}

void Turnout::setDivergent() {
  this->pwm.setPWM(this->index, 0, pulseWidth(this->divergent));
  digitalWrite(this->straigtLedIndex, LOW);
  digitalWrite(this->divergentLedIndex, HIGH);
  this->current = this->divergent;
}
