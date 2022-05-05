//
// Created by buimi on 5/3/2022.
//

#include "Screen.h"

#include <Arduino.h>

#include "OutputDevice.h"

byte ArrowShape[] = {B11000, B11100, B11110, B11111,
                     B11111, B11110, B11100, B11000};

Screen::Screen(const uint8_t pin1, const uint8_t pin2, const uint8_t pin3,
               const uint8_t pin4, const uint8_t pin5, const uint8_t pin6,
               const char* name)
    : OutputDevice<String>(name), lcd(pin1, pin2, pin3, pin4, pin5, pin6) {
  reset_lcd();
}
// Write the content string on the screen
void Screen::write(const String& content) { lcd.print(content); }

void Screen::reset_lcd() {
  lcd.begin(16, 2);
  lcd.createChar(1, ArrowShape);
}

void Screen::clear_lcd() { lcd.clear(); }

void Screen::draw_arrow(uint8_t line) {
  lcd.setCursor(0, line);
  lcd.write(1);
}
