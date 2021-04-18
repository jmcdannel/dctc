#ifndef DCTC_TRACK_H
#define DCTC_TRACK_H

#include <Arduino.h>
#include <Pushbutton.h>

class Track {

  private:
    bool state;
    int buttonPin;
    int relayPin;
    int LEDPin;
    Pushbutton button;

  public:
    Track(int buttonPin, int relayPin, int LEDPin);

    void setup();
    void loop();
};

#endif
