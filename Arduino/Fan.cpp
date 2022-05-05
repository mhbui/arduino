//
// Created by buimi on 5/3/2022.
//

#include "Fan.h"

#include <Arduino.h>
// Activate Fan with its speed
void Fan::write(const uint8_t &speed) { analogWrite(pin_, speed); }