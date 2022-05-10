//
// Created by buimi on 5/3/2022.
//

#include "Fan.h"

#include <Arduino.h>
Fan::Fan(const uint8_t pin, const char *name)
    : OutputDevice<uint8_t>(name), pin_(pin) {
  pinMode(pin_, OUTPUT);
}
// Activate Fan with its speed
void Fan::write(const uint8_t &speed) { analogWrite(pin_, speed); }