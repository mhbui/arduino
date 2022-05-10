//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_TEMPSENSOR_H
#define BE_ARDUINO_TEMPSENSOR_H

#include "InputDevice.h"

class TempSensor : public InputDevice<float> {
 private:
  TempSensor(const int pin, const char* name);
  const uint8_t pin_;

 public:
  TempSensor(const uint8_t pin, const char* name = "Temperature");


  const float& read() override;
};

#endif  // BE_ARDUINO_TEMPSENSOR_H
