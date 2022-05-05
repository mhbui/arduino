//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_CENTRAL_H
#define BE_ARDUINO_CENTRAL_H

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "Fan.h"
#include "JoyStick.h"
#include "MainMenu.h"
#include "Menu.h"
#include "MusicMenu.h"
#include "Screen.h"
#include "Speaker.h"
#include "TempSensor.h"
#include "UltraSoundSensor.h"

class Central {
 private:
  Fan fan_;
  JoyStick joy_stick_;
  Screen screen_;
  Speaker speaker_;
  TempSensor temp_sensor_;
  UltraSoundSensor ultra_sound_sensor_;

  MainMenu main_menu_;
  MusicMenu music_menu_;

  uint8_t menu_idx_;
  Menu* menus_[2];
  // Variable which gives us the indication whether we must refresh the
  // interface or not
  bool need_refresh_gui_;
  Direction prev_direction_;

  void gui();

 public:
  Central();

  void loop();
};

#endif  // BE_ARDUINO_CENTRAL_H
