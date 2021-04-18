#ifndef DCTC_EFFECT_H
#define DCTC_EFFECT_H

#include <Arduino.h>
#include <Pushbutton.h>

class Effect {

  private:
    bool state;
    int inputPin;
    int outputPin;
    Pushbutton button;

  public:
    Effect(int inputPin, int outputPin);

    void setup();
    void loop();
};

#endif
