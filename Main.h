#ifndef MAIN
#define MAIN

#include "Arduino.h"
#include <virtuabotixRTC.h>
#include <Component_Button.h>
#include <LiquidCrystal.h>

const int16_t
  PIN_RTC_CLK = 6,
  PIN_RTC_DAT = 7,
  PIN_RTC_RESET = 8;
virtuabotixRTC hwRTC(
  PIN_RTC_CLK,
  PIN_RTC_DAT,
  PIN_RTC_RESET
);

const int16_t
  PIN_LCD_RS = 5,
  PIN_LCD_EN = 12,
  PIN_LCD_D4 = 10,
  PIN_LCD_D5 = 9,
  PIN_LCD_D6 = 3,
  PIN_LCD_D7 = 11;
LiquidCrystal lcd(
  PIN_LCD_RS,
  PIN_LCD_EN,
  PIN_LCD_D4,
  PIN_LCD_D5,
  PIN_LCD_D6,
  PIN_LCD_D7);
const int
  LCD_COLS = 16,
  LCD_ROWS = 2;

const int16_t PIN_BTN_SET_TIME = 2;
Button btnSetTime(PIN_BTN_SET_TIME);

unsigned long lastPrintTime;

void lcdPrint(String s1, String s2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s1);
  lcd.setCursor(0, 1);
  lcd.print(s2);
}

void printTime() {
  if (millis() - 1000 > lastPrintTime) {
    lastPrintTime = millis();
    hwRTC.updateTime();
    Serial.print("Time: ");
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

    lcdPrint(
        String(hwRTC.dayofmonth)
      + "/"
      + String(hwRTC.month)
      + "/"
      + String(hwRTC.year)
    ,
        String(hwRTC.hours)
      + ":"
      + String(hwRTC.minutes)
      + ":"
      + String(hwRTC.seconds)
    );
  }
}


class Main {
  public:
    static void setup() {
      lastPrintTime = millis();
      lcd.begin(LCD_COLS, LCD_ROWS);
      lcdPrint("Ready!", "Arduino");
      delay(3000);
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