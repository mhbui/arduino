//
// Created by buimi on 5/3/2022.
//

#include "UltraSoundSensor.h"

#include <Arduino.h>

// Return the current distance from the Ultrasound Sensor
const uint8_t &UltraSoundSensor::read() {
  // Clears the trigger_pin_ condition
  digitalWrite(trigger_pin_, LOW);
  delayMicroseconds(2);

  // Sets the trigger_pin_ HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigger_pin_, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin_, LOW);

  // Reads the echo_pin_, returns the sound wave travel time in microseconds
  unsigned long duration = pulseIn(echo_pin_, HIGH);

  // Calculating the distance
  // Speed of sound wave divided by 2 (go and back)
  data_ = (uint8_t)(duration * 0.034 / 2);

  return data_;
}
