
#include "Cab.h"
#include "Turnout.h"
#include "Track.h"
#include "Effect.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// PWM
#define FREQUENCY 50

// Cab 1
#define CAB_1_TROTTLE_PIN A2
#define CAB_1_BUTTON_PIN 22
#define CAB_1_FWD_PIN 23
#define CAB_1_REV_PIN 24
#define CAB_1_POWER_PIN 12
#define CAB_1_BRAKE_PIN 9
#define CAB_1_SPEED_PIN 3

// Cab 2
#define CAB_2_TROTTLE_PIN A3
#define CAB_2_BUTTON_PIN 25
#define CAB_2_FWD_PIN 26
#define CAB_2_REV_PIN 27
#define CAB_2_POWER_PIN 13
#define CAB_2_BRAKE_PIN 8
#define CAB_2_SPEED_PIN 11

// Turnout 1 (Red)
#define T1_SERVO_IDX 0
#define T1_BUTTON_PIN 28
#define T1_STRAIGHT_PIN 29
#define T1_DIVERGENT_PIN 30
#define T1_STRAIGHT_ANGLE 30
#define T1_DIVERGENT_ANGLE 150

// Turnout 2 (Green)
#define T2_SERVO_IDX 1
#define T2_BUTTON_PIN 31
#define T2_STRAIGHT_PIN 32
#define T2_DIVERGENT_PIN 33
#define T2_STRAIGHT_ANGLE 30
#define T2_DIVERGENT_ANGLE 150

// Track 1
#define TRACK_1_RELAY_PIN 34
#define TRACK_1_LED_PIN 35
#define TRACK_1_BUTTON_PIN 36

// Track 2
#define TRACK_2_RELAY_PIN 37
#define TRACK_2_LED_PIN 38
#define TRACK_2_BUTTON_PIN 39

// Track 3
#define TRACK_3_RELAY_PIN 40
#define TRACK_3_LED_PIN 41
#define TRACK_3_BUTTON_PIN 42

// Track 4
#define TRACK_4_RELAY_PIN 43
#define TRACK_4_LED_PIN 44
#define TRACK_4_BUTTON_PIN 45

// Effect: Station Lighting
#define STATION_LIGHTS_PIN 46
#define STATION_LIGHTS_BUTTON_PIN 47

// Effect: Tunnel Lights
#define TUNNEL_LIGHTS_PIN 48
#define TUNNEL_LIGHTS_BUTTON_PIN 49

// Effect: Station Sounds
#define STATION_SOUNDS_PIN 50
#define STATION_SOUNDS_BUTTON__PIN 51

Cab cab1 = Cab(CAB_1_TROTTLE_PIN, CAB_1_BUTTON_PIN, CAB_1_POWER_PIN, CAB_1_BRAKE_PIN, CAB_1_SPEED_PIN, CAB_1_FWD_PIN, CAB_1_REV_PIN);
Cab cab2 = Cab(CAB_2_TROTTLE_PIN, CAB_2_BUTTON_PIN, CAB_2_POWER_PIN, CAB_2_BRAKE_PIN, CAB_2_SPEED_PIN, CAB_2_FWD_PIN, CAB_2_REV_PIN);

Turnout turnout1 = Turnout(T1_SERVO_IDX, T1_STRAIGHT_ANGLE, T1_DIVERGENT_ANGLE, T1_BUTTON_PIN, T1_STRAIGHT_PIN, T1_DIVERGENT_PIN);
Turnout turnout2 = Turnout(T2_SERVO_IDX, T2_STRAIGHT_ANGLE, T2_DIVERGENT_ANGLE, T2_BUTTON_PIN, T2_STRAIGHT_PIN, T2_DIVERGENT_PIN);

Track track1 = Track(TRACK_1_BUTTON_PIN, TRACK_1_RELAY_PIN, TRACK_1_LED_PIN);
Track track2 = Track(TRACK_2_BUTTON_PIN, TRACK_2_RELAY_PIN, TRACK_2_LED_PIN);
Track track3 = Track(TRACK_3_BUTTON_PIN, TRACK_3_RELAY_PIN, TRACK_3_LED_PIN);
Track track4 = Track(TRACK_4_BUTTON_PIN, TRACK_4_RELAY_PIN, TRACK_4_LED_PIN);

Effect stationLights = Effect(STATION_LIGHTS_BUTTON_PIN, STATION_LIGHTS_PIN);
Effect tunnelLights = Effect(TUNNEL_LIGHTS_BUTTON_PIN, TUNNEL_LIGHTS_PIN);
Effect stationSounds = Effect(STATION_SOUNDS_BUTTON__PIN, STATION_SOUNDS_PIN);

void setup() {
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  
  cab1.setup();
  cab2.setup();
  
  turnout1.setup(pwm);
  turnout2.setup(pwm);
  
  track1.setup();
  track2.setup();
  track3.setup();
  track4.setup();
  
  stationLights.setup();
  tunnelLights.setup();
  stationSounds.setup();
}

void loop() {
  cab1.loop();
  cab2.loop();
  
  turnout1.loop();
  turnout2.loop();
  
  track1.loop();
  track2.loop();
  track3.loop();
  track4.loop();
  
  stationLights.loop();
  tunnelLights.loop();
  stationSounds.loop();
}
