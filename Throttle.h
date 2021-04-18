#ifndef DCTC_THROTTLE_H
#define DCTC_THROTTLE_H

#include <Arduino.h>

class Throttle {

  private:
    int throttlePin;
    int speedPin;
    int value;

  public:
    Throttle();

    void setup(int throttlePin, int speedPin);
    void loop();
    
    int currentSpeed;
};

#endif
