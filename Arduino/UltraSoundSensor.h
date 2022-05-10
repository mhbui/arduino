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
                   const char* name = "Distance");


  const uint8_t& read() override;
};

#endif  // BE_ARDUINO_ULTRASOUNDSENSOR_H
