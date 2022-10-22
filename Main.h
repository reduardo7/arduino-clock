#include "Arduino.h"
#ifndef MAIN
#define MAIN

#include <virtuabotixRTC.h>
#include <Component_Button.h>

#define PIN_RTC_CLK 6
#define PIN_RTC_DAT 7
#define PIN_RTC_RESET 8

#define PIN_BTN_SET_TIME 4

virtuabotixRTC hwRTC(
  PIN_RTC_CLK,
  PIN_RTC_DAT,
  PIN_RTC_RESET
);

Button btnSetTime(PIN_BTN_SET_TIME);

#define PRINT_INTERVAL 1000
unsigned long lastPrintTime;

void printTime() {
  if (millis() - PRINT_INTERVAL > lastPrintTime) {
    lastPrintTime = millis();
    hwRTC.updateTime();
    Serial.print("Date-Time: ");
    Serial.print(hwRTC.dayofmonth);
    Serial.print("/");
    Serial.print(hwRTC.month);
    Serial.print("/");
    Serial.print(hwRTC.year);
    Serial.print(" ");
    Serial.print(hwRTC.hours);
    Serial.print(":");
    Serial.print(hwRTC.minutes);
    Serial.print(":");
    Serial.println(hwRTC.seconds);
  }
}

class Main {
  public:
    static void setup() {
      lastPrintTime = millis();
    }

    static void loop() {
      if (btnSetTime.onClick()) {
        Serial.println("Updating...");
        hwRTC.setDS1302Time(00, 45, 15, 7, 9, 2, 2019);
        Serial.println("UPDATRED!");
      }

      printTime();
    }
};

#endif