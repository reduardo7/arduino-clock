#ifndef MODULE_MAIN
#define MODULE_MAIN

#include "Arduino.h"
#include "Lcd.h"
#include "Rtc.h"
#include "PrintTime.h"
#include "Utils.h"
#include <Component_Button.h>

const int16_t PIN_BTN_SET_TIME = 2;
Button btnSetTime(PIN_BTN_SET_TIME);

class Main {
  public:
    static void setup() {}

    static void loop() {
      if (btnSetTime.onClick()) {
        Serial.println("Updating...");
        Rtc.setDS1302Time(00, 45, 15, 7, 9, 2, 2019);
      }
    }
};

#endif