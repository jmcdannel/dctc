#ifndef DCTC_CAB_H
#define DCTC_CAB_H

#include <Arduino.h>
#include "Throttle.h"
#include <Pushbutton.h>

class Cab {

  private:
    byte currentDirection;
    int currentSpeed;
    int throttlePin;
    int switchPin;
    int powerPin;
    int brakePin;
    int speedPin;
    int fwdLedIndex;
    int revLedIndex;
    Throttle throttle;
    Pushbutton button;

  public:
    Cab(int throttlePin, int switchPin, int powerPin, int brakePin, int speedPin, int fwdLedPin, int revLedPin);

    void setup();
    void loop();
};

#endif
