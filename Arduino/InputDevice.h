//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_INPUTDEVICE_H
#define BE_ARDUINO_INPUTDEVICE_H

#include <Arduino.h>

#include "Device.h"

template <typename T>
class InputDevice : public Device {
 private:
  const char *unit_;

 protected:
  T data_;

 public:
  InputDevice(const char *name, const char *unit) : Device(name), unit_(unit) {}

  virtual const T &read() = 0;
};

#endif  // BE_ARDUINO_INPUTDEVICE_H
