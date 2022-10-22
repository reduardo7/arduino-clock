#ifndef PRINT_TIME
#define PRINT_TIME

#include "Arduino.h"
#include "Lcd.h"
#include "Rtc.h"
#include <Lib_Interval.h>

class PrintTime: public Runnable {
  private:
    Interval interval;

  protected:
    void onSetup() {}

    void onLoop() {
      if (this->interval.onStep()) {
        Rtc.updateTime();
        Serial.print("Time: ");
        Serial.print(Rtc.dayofmonth);
        Serial.print("/");
        Serial.print(Rtc.month);
        Serial.print("/");
        Serial.print(Rtc.year);
        Serial.print(" ");
        Serial.print(Rtc.hours);
        Serial.print(":");
        Serial.print(Rtc.minutes);
        Serial.print(":");
        Serial.println(Rtc.seconds);

        Lcd::print(
            String(Rtc.dayofmonth)
          + "/"
          + String(Rtc.month)
          + "/"
          + String(Rtc.year)
        ,
            String(Rtc.hours)
          + ":"
          + String(Rtc.minutes)
          + ":"
          + String(Rtc.seconds)
        );
      }        
    }

  public:
    PrintTime() :
      interval(1000)
      {}
};

// Init
PrintTime _printTime;

#endif