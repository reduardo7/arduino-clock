#ifndef MODULE_BUZZER
#define MODULE_BUZZER

#include <App_Runnable.h>
#include <Lib_Interval.h>
#include <Lib_Timer.h>

#define PIN_BUZZER 11

#define TIME_INTERVAL 10

class Buzzer: public Runnable {
  private:
    Interval interval;
    Timer timerRing;
    unsigned int step = 0;
    bool upper = true;

  protected:
    void onSetup() {
      pinMode(PIN_BUZZER, OUTPUT);
      this->stop();
    }

    void onLoop() {
      if (this->interval.onStep()) {
        if (this->upper) {
          analogWrite(PIN_BUZZER, this->step);
        } else {
          analogWrite(PIN_BUZZER, 255 - this->step);
        }
        
        this->step++;

        if (this->step = 255) {
          this->step = 0;
          this->upper = !this->upper;
        }
      }

      if (this->interval.isFinished()) {
        analogWrite(PIN_BUZZER, 0);
      }

      if (this->timerRing.onFinish()) {
        Serial.println("Buzzer timer finish");
        this->stop();
      }
    }

  public:
    Buzzer() :
      interval(TIME_INTERVAL),
      timerRing(10000)
      {}

    void start() {
      Serial.println("Buzzer START");
      this->step = 0;
      this->upper = true;
      this->interval.start(TIME_INTERVAL);
    }

    void stop() {
      Serial.println("Buzzer STOP");
      analogWrite(PIN_BUZZER, 0);
      this->interval.stop();
    }

    void ring() {
      Serial.println("Buzzer RING");
      this->start();
      this->timerRing.start(10 * 1000);
    }

    bool isRinging() {
      return this->interval.isRunning();
    }
};

#endif