#ifndef MODULE_PRINT_TIME
#define MODULE_PRINT_TIME

#include "Arduino.h"
#include "Lcd.h"
#include "Rtc.h"
#include "Utils.h"
#include <Lib_Interval.h>

Lcd lcd;

class PrintTime: public Runnable {
  private:
    Interval interval;

  protected:
    void onSetup() {}

    void onLoop() {
      if (this->interval.onStep()) {
        Rtc.updateTime();
        Serial.print("Time: ");
        Serial.print(digitPad(Rtc.dayofmonth));
        Serial.print("/");
        Serial.print(digitPad(Rtc.month));
        Serial.print("/");
        Serial.print(Rtc.year);
        Serial.print(" ");
        Serial.print(digitPad(Rtc.hours));
        Serial.print(":");
        Serial.print(digitPad(Rtc.minutes));
        Serial.print(":");
        Serial.println(digitPad(Rtc.seconds));

        lcd.print(
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

// Init - Create an instance and keep it working in paralell
PrintTime _printTime;

#endif