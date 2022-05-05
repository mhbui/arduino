//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_OUTPUTDEVICE_H
#define BE_ARDUINO_OUTPUTDEVICE_H

#include <Arduino.h>

#include "Device.h"
// Use template because we can write different types of data
template <typename T>
class OutputDevice : public Device {
 public:
  OutputDevice(const char* name) : Device(name) {}

  virtual void write(const T& value) = 0;
};

#endif  // BE_ARDUINO_OUTPUTDEVICE_H
