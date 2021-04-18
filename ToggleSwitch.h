#ifndef DCTC_TOGGLESWITCH_H
#define DCTC_TOGGLESWITCH_H

#include <Arduino.h>

class ToggleSwitch {

  private:
    int switchPin;

  public:
    ToggleSwitch();

    void setup(int switchPin);
    void loop();

    int state;
    bool isChanged;
};

#endif
