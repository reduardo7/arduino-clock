#ifndef MODULE_PRINT_TIME
#define MODULE_PRINT_TIME

#include "Arduino.h"
#include "Lcd.h"
#include "Rtc.h"
#include "Utils.h"
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
            digitPad(Rtc.dayofmonth)
          + "/"
          + digitPad(Rtc.month)
          + "/"
          + String(Rtc.year)
        ,
            " "
          + digitPad(Rtc.hours)
          + ":"
          + digitPad(Rtc.minutes)
          + ":"
          + digitPad(Rtc.seconds)
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