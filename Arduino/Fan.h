//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_FAN_H
#define BE_ARDUINO_FAN_H

#include <Arduino.h>

#include "OutputDevice.h"

class Fan : public OutputDevice<uint8_t> {
 private:
  const uint8_t pin_;

 public:
  Fan(const uint8_t pin, const char* name = "Fan")
      : OutputDevice<uint8_t>(name), pin_(pin) {
    pinMode(pin_, OUTPUT);
  }

  void write(const uint8_t& speed) override;
};

#endif  // BE_ARDUINO_FAN_H
