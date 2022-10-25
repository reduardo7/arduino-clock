#ifndef MODULE_RTC
#define MODULE_RTC

#include "Arduino.h"
#include <virtuabotixRTC.h>

#define PIN_RTC_CLK 6
#define PIN_RTC_DAT 7
#define PIN_RTC_RESET 8

virtuabotixRTC Rtc(
  PIN_RTC_CLK,
  PIN_RTC_DAT,
  PIN_RTC_RESET
);

#endif