//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_SCREEN_H
#define BE_ARDUINO_SCREEN_H

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "OutputDevice.h"

class Screen : public OutputDevice<String> {
 public:
  Screen(const uint8_t pin1, const uint8_t pin2, const uint8_t pin3,
         const uint8_t pin4, const uint8_t pin5, const uint8_t pin6,
         const char* name = "LCD");

  void write(const String& content) override;

  void reset_lcd();
  void clear_lcd();

  void draw_arrow(uint8_t line);

  LiquidCrystal lcd;
};

#endif  // BE_ARDUINO_SCREEN_H
