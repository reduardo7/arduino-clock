# arduino-clock

## Components

- Arduino UNO Board.
- 1 Switch.
- 1 Buzzer.
- 1 Liquid Crystal Displays (LCD).
- 1 potentiometer 10kΩ.
- 1 220Ω resistor.
- 1 RTC module.
- Hook-up wires.
- Breadboard.

## Connection

- `Pin 2` --> **Switch (1)**
- `Pin 3` --> **LCD D6**
- `Pin 4` -->
- `Pin 5` --> **LCD RS**
- `Pin 6` --> **RTC CLK**
- `Pin 7` --> **RTC DAT**
- `Pin 8` --> **RTC RST**
- `Pin 9` --> **LCD D5**
- `Pin 10` --> **LCD D4**
- `Pin 11` --> **Buzzer (+)**
- `Pin 12` --> **LCD D7**
- `Pin 13` --> **LCD Enable**
- **LCD VSS** --> _GND_
- **Switch (2)** --> _GND_
- **Buzzer (-)** --> _GND_
- **220Ω resistor (1)** --> **LCD VDD**
- **220Ω resistor (2)** --> _5v_
- **10kΩ potentiometer (1)** -> _5v_
- **10kΩ potentiometer (2)** -> **LCD VDD**
- **10kΩ potentiometer (3)** -> _GND_
- **RTC VCC** --> _5v_
- **RTC GND** --> _GND_

LCD D7 pin to digital pin 2
LCD R/W pin to GND
LCD VSS pin to GND
LCD VCC pin to 5V
LCD LED+ to 5V through a 220 ohm resistor
LCD LED- to GND

## Arduino Libraries

- [`virtuabotixRTC`](https://github.com/chrisfryer78/ArduinoRTClibrary)
- [`arduino-robot`](https://github.com/reduardo7/arduino-robot)
- [`LiquidCrystal`](https://github.com/arduino-libraries/LiquidCrystal)

## Doc

- <https://eloctavobit.com/arduino/real-time-clock-rtc-ds1302-modulo-reloj>
- <https://github.com/chrisfryer78/ArduinoRTClibrary>
- <https://docs.arduino.cc/learn/electronics/lcd-displays>
