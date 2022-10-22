#include "Main.h"

// https://eloctavobit.com/arduino/real-time-clock-rtc-ds1302-modulo-reloj/
// https://github.com/chrisfryer78/ArduinoRTClibrary

void setup() {
  Serial.begin(9600);

  Runnable::setupAll();
  Lcd::setup();
  Main::setup();

  Serial.println("Ready");
}

void loop() {
  Runnable::loopAll();
  Main::loop();
}