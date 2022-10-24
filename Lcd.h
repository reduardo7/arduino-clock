#ifndef LCD
#define LCD

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

class Lcd {
  private:
    static LiquidCrystal _lcd;

  public:
    static LiquidCrystal getLcd() { return _lcd; }

    static void setup() {
      _lcd.begin(LCD_COLS, LCD_ROWS);
      print("LCD Ready!", "Arduino");
      delay(3000);
    }

    static void print(String s1, String s2) {
      Serial.print("LCD1: "); Serial.println(s1);
      Serial.print("LCD2: "); Serial.println(s2);
      _lcd.clear();
      _lcd.setCursor(0, 0);
      _lcd.print(s1);
      _lcd.setCursor(0, 1);
      _lcd.print(s2);
    }
};

LiquidCrystal Lcd::_lcd(
  PIN_LCD_RS,
  PIN_LCD_EN,
  PIN_LCD_D4,
  PIN_LCD_D5,
  PIN_LCD_D6,
  PIN_LCD_D7
);

#endif