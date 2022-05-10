//
// Created by buimi on 5/3/2022.
//

#include "TempSensor.h"

#include <Arduino.h>

TempSensor::TempSensor(const uint8_t pin, const char *name)
    : InputDevice<float>(name, "C"), pin_(pin) {}

// Return the current temperature from TempSensor
const float &TempSensor::read() {
  int analog = analogRead(pin_);
  float R = 1023.0 / analog - 1;
  data_ = 1 / (logf(R) / 4275 + 1 / 298.15) - 273.15;
  return data_;
}
