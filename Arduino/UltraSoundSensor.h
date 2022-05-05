//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_ULTRASOUNDSENSOR_H
#define BE_ARDUINO_ULTRASOUNDSENSOR_H

#include "InputDevice.h"

class UltraSoundSensor : InputDevice<uint8_t> {
 private:
  const uint8_t trigger_pin_;
  const uint8_t echo_pin_;

 public:
  UltraSoundSensor(const uint8_t trigger_pin, const uint8_t echo_pin,
                   const char* name = "Distance")
      : InputDevice<uint8_t>(name, "cm"),
        trigger_pin_(trigger_pin),
        echo_pin_(echo_pin) {
    pinMode(trigger_pin_, OUTPUT);
    pinMode(echo_pin_, INPUT);
  }

  const uint8_t& read() override;
};

#endif  // BE_ARDUINO_ULTRASOUNDSENSOR_H
