//
// Created by buimi on 5/3/2022.
//

#include "Central.h"

#include <Arduino.h>

#include "Fan.h"
#include "JoyStick.h"
#include "MainMenu.h"
#include "Menu.h"
#include "MusicMenu.h"
#include "Screen.h"
#include "Speaker.h"
#include "TempSensor.h"
#include "UltraSoundSensor.h"

Central::Central()
    : fan_(A5),
      joy_stick_(A3, A4),
      screen_(4, 6, 10, 11, 12, 13),
      speaker_(A2),
      temp_sensor_(A0),
      ultra_sound_sensor_(5, 7),
      main_menu_(screen_, temp_sensor_, ultra_sound_sensor_, fan_),
      music_menu_(speaker_),
      menu_idx_(0),
      menus_({&main_menu_, &music_menu_}),
      need_refresh_gui_(true),
      prev_direction_(Direction::no) {}

void Central::gui() {
  Menu& current_menu_ = *menus_[menu_idx_];
  if (!current_menu_.scrollable()) {
    current_menu_.action();
  } else {
    if (!need_refresh_gui_) return;

    screen_.clear_lcd();

    uint8_t idx = current_menu_.current_idx();
    uint8_t size = current_menu_.size();
    uint8_t line = current_menu_.current_line();
    uint8_t display = (idx + size - line) % size;

    screen_.lcd.setCursor(1, 0);

    screen_.lcd.print(current_menu_[display]);
    screen_.lcd.setCursor(1, 1);
    screen_.lcd.print(current_menu_[(display + 1) % size]);
    screen_.draw_arrow(line);

    need_refresh_gui_ = false;
  }
}

void Central::loop() {
  Menu& current_menu_ = *menus_[menu_idx_];
  gui();

  Direction direction = joy_stick_.read();
  if (direction == prev_direction_) return;

  if (direction == Direction::up || direction == Direction::down) {
    current_menu_.scroll(direction);
    need_refresh_gui_ = true;
  }

  if (direction == Direction::right) {
    int8_t signal = current_menu_.right();
    need_refresh_gui_ = true;
    menu_idx_ += signal;
  }

  if (direction == Direction::left) {
    int8_t signal = current_menu_.left();
    need_refresh_gui_ = true;
    menu_idx_ += signal;
  }

  prev_direction_ = direction;
}
