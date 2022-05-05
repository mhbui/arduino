//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_MENU_H
#define BE_ARDUINO_MENU_H

#include <Arduino.h>

#include "JoyStick.h"

class Menu {
 protected:
  // The line of the menu (0/1)
  uint8_t line_;
  // The index of the current menu items (GetTemp/GetDist/PlaySong/TurnOnFan for the Main Menu)
  uint8_t idx_;

  const char* const* items_;
  // The size of the current menu (4 for the Main Menu)
  uint8_t size_;
  // The state of the Joystick in the Menu (Scrollable or not)
  bool scrollable_;

 public:
  Menu(const char* const* items, uint8_t size);
  // Scroll Up Down
  void scroll(Direction direction);

  virtual int8_t action() = 0;
  virtual int8_t right() = 0;
  virtual int8_t left() = 0;
  // Return the display string
  const char* operator[](uint8_t idx) const;

  uint8_t current_line() const;
  uint8_t current_idx() const;
  uint8_t size() const;
  bool scrollable() const;
};

#endif  // BE_ARDUINO_MENU_H
