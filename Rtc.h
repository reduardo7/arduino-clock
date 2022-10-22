#ifndef RTC
#define RTC

#include "Arduino.h"
#include <virtuabotixRTC.h>

const int16_t
  PIN_RTC_CLK = 6,
  PIN_RTC_DAT = 7,
  PIN_RTC_RESET = 8;

virtuabotixRTC Rtc(
  PIN_RTC_CLK,
  PIN_RTC_DAT,
  PIN_RTC_RESET
);

#endif