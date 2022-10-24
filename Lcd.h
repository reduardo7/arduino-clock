#ifndef MODULE_LCD
#define MODULE_LCD

// https://www.instructables.com/how-to-interface-LCD-16X2-to-arduino/

#include <App_Runnable.h>
#include <LiquidCrystal.h>

const int16_t
  PIN_LCD_RS = 5,
  PIN_LCD_EN = 12,
  PIN_LCD_D4 = 10,
  PIN_LCD_D5 = 9,
  PIN_LCD_D6 = 3,
  PIN_LCD_D7 = 11;
  
const int
  LCD_COLS = 16,
  LCD_ROWS = 2;

class Lcd: public Runnable {
  private:
    LiquidCrystal _lcd;

  protected:
    void onSetup() {
      this->_lcd.begin(LCD_COLS, LCD_ROWS);
      print("LCD Ready", "Arduino");
    }

  public:
    Lcd() :
      _lcd(
        PIN_LCD_RS,
        PIN_LCD_EN,
        PIN_LCD_D4,
        PIN_LCD_D5,
        PIN_LCD_D6,
        PIN_LCD_D7
      )
      {}

    LiquidCrystal getLcd() { return this->_lcd; }

    void print(String s1, String s2) {
      Serial.print("LCD1: "); Serial.println(s1);
      Serial.print("LCD2: "); Serial.println(s2);
      // this->_lcd.clear();
      this->_lcd.setCursor(0, 0);
      this->_lcd.print(s1);
      this->_lcd.setCursor(0, 1);
      this->_lcd.print(s2);
    }
};

#endif