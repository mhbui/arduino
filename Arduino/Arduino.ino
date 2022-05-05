#include <Arduino.h>

#include "Central.h"

Central central;

void setup() { Serial.begin(9600); }

void loop() { central.loop(); }
