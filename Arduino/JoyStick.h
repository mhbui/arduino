//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_JOYSTICK_H
#define BE_ARDUINO_JOYSTICK_H

#include "InputDevice.h"

// Enumerator class Direction to define directions
enum class Direction : uint8_t {
  no = 0x00,
  left = 0x01,
  right = 0x02,
  up = 0x04,
  down = 0x08
};

class JoyStick : public InputDevice<Direction> {
 private:
  JoyStick(const int pin_x, const int pin_y, const char *name);
  const uint8_t pin_x_;
  const uint8_t pin_y_;

 public:
  JoyStick(const uint8_t pin_x, const uint8_t pin_y,
           const char *name = "JoyStick");

  const Direction &read() override;
};

#endif  // BE_ARDUINO_JOYSTICK_H
