#ifndef MODULE_MAIN
#define MODULE_MAIN

#include "Arduino.h"
#include "Lcd.h"
#include "Rtc.h"
#include "PrintTime.h"
#include "Buzzer.h"
#include <Component_Button.h>

#define TIME_SEC 45
#define TIME_MIN 45
#define TIME_HRS 15
#define TIME_WEEK 5
#define TIME_DAY 9
#define TIME_MONTH 2
#define TIME_YEAR 2022

// Alarm
#define ALARM_MIN 46
#define ALARM_HRS 15
#define ALARM_DAY 9
#define ALARM_MONTH 2
#define ALARM_YEAR 2022

#define PIN_BTN_SET_TIME 2
Button btnSetTime(PIN_BTN_SET_TIME);

Buzzer buzzer;

class Main {
  public:
    static void setup() {}

    static void loop() {
      if (btnSetTime.onClick()) {
        Serial.println("Updating...");
        Rtc.setDS1302Time(
          TIME_SEC,
          TIME_MIN,
          TIME_HRS,
          TIME_WEEK,
          TIME_DAY,
          TIME_MONTH,
          TIME_YEAR
        );
      }

      if (
        !buzzer.isRinging()
        && ALARM_DAY   == Rtc.dayofmonth
        && ALARM_MONTH == Rtc.month
        && ALARM_YEAR  == Rtc.year
        && ALARM_HRS   == Rtc.hours
        && ALARM_MIN   == Rtc.minutes
        && 5           >  Rtc.seconds // Start ringing at first 5 seconds
      ) {
        Serial.println("Ringgg!!!");
        buzzer.ring();
      }
    }
};

#endif