//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_DEVICE_H
#define BE_ARDUINO_DEVICE_H

#include <Arduino.h>

class Device {
 protected:
  const char* name_;
  Device(const char* name) : name_(name) {}

 public:
  String get_debug_string();
  void print_debug_string();
};

#endif  // BE_ARDUINO_DEVICE_H
