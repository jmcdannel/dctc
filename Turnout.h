#ifndef DCTC_TURNOUT_H
#define DCTC_TURNOUT_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Pushbutton.h>

class Turnout {

  private:
    int index;
    int current;
    int straight;
    int divergent;
    int buttonPin;
    int straigtLedIndex;
    int divergentLedIndex;
    Adafruit_PWMServoDriver pwm;
    Pushbutton button;

  public:
    Turnout(int index, int straight, int divergent, int buttonPin, int straigtLedIndex, int divergentLedIndex);

    void setup(Adafruit_PWMServoDriver pwm);
    void loop();
    int pulseWidth(int angle);
    void setStraight();
    void setDivergent();
};

#endif
