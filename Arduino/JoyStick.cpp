//
// Created by buimi on 5/3/2022.
//

#include "JoyStick.h"

#include <Arduino.h>

constexpr int LEFT_THRESHOLD = 400;
constexpr int RIGHT_THRESHOLD = 800;
constexpr int UP_THRESHOLD = 400;
constexpr int DOWN_THRESHOLD = 800;
JoyStick::JoyStick(const uint8_t pin_x, const uint8_t pin_y, const char *name)
    : InputDevice<Direction>(name, ""), pin_x_(pin_x), pin_y_(pin_y) {}

// Return the current direction of the Joystick (Left/Right/Up/Down/No)
const Direction &JoyStick::read() {
  int val_x = analogRead(pin_x_);
  int val_y = analogRead(pin_y_);

  uint8_t command = static_cast<uint8_t>(Direction::no);

  if (val_x < LEFT_THRESHOLD) {
    command |= static_cast<uint8_t>(Direction::left);
  } else if (val_x > RIGHT_THRESHOLD) {
    command |= static_cast<uint8_t>(Direction::right);
  }
  if (val_y < UP_THRESHOLD) {
    command |= static_cast<uint8_t>(Direction::up);
  } else if (val_y > DOWN_THRESHOLD) {
    command |= static_cast<uint8_t>(Direction::down);
  }

  data_ = Direction::no;
  if (command & static_cast<uint8_t>(Direction::left)) {
    data_ = Direction::left;
  }
  if (command & static_cast<uint8_t>(Direction::right)) {
    data_ = Direction::right;
  }
  if (command & static_cast<uint8_t>(Direction::up)) {
    data_ = Direction::up;
  }
  if (command & static_cast<uint8_t>(Direction::down)) {
    data_ = Direction::down;
  }

  return data_;
}
