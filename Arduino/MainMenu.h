//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_MAINMENU_H
#define BE_ARDUINO_MAINMENU_H

#include <Arduino.h>

#include "Fan.h"
#include "Menu.h"
#include "Screen.h"
#include "TempSensor.h"
#include "UltraSoundSensor.h"

class MainMenu : public Menu {
 private:
  void temperature();
  void distance();
  void fan();

  Screen& screen_;

  TempSensor& temp_sensor_;
  UltraSoundSensor& ultra_sound_sensor_;

  Fan& fan_;
  bool use_fan_;

  unsigned long prev_millis_;

 public:
  MainMenu(Screen& screen, TempSensor& temp_sensor,
           UltraSoundSensor& ultra_sound_sensor, Fan& fan);

  int8_t action() override;
  int8_t right() override;
  int8_t left() override;
};

#endif  // BE_ARDUINO_MAINMENU_H
