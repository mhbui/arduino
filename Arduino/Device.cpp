//
// Created by buimi on 5/3/2022.
//

#include "Device.h"

#include <Arduino.h>

// return a string for debugging purpose
String Device::get_debug_string() { return name_; }
void Device::print_debug_string() { Serial.print(get_debug_string()); }
