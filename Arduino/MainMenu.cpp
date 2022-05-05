//
// Created by buimi on 5/3/2022.
//

#include "MainMenu.h"

#include <Arduino.h>

const char* MainMenuItems[] = {"Get temperature", "Get distance", "Play song",
                               "Turn on fan"};

constexpr unsigned long UPDATE_INTERVAL_MILLIS = 1000;

MainMenu::MainMenu(Screen& screen, TempSensor& temp_sensor,
                   UltraSoundSensor& ultra_sound_sensor, Fan& fan)
    : Menu(MainMenuItems, sizeof(MainMenuItems) / sizeof(const char*)),
      screen_(screen),
      temp_sensor_(temp_sensor),
      ultra_sound_sensor_(ultra_sound_sensor),
      fan_(fan),
      use_fan_(false),
      prev_millis_(-UPDATE_INTERVAL_MILLIS) {}

void MainMenu::temperature() {
  screen_.lcd.print("Temperature");
  screen_.lcd.setCursor(0, 1);
  screen_.lcd.print(String(temp_sensor_.read()) + " C");
}

void MainMenu::distance() {
  screen_.lcd.print("Distance");
  screen_.lcd.setCursor(0, 1);
  screen_.lcd.print(String(ultra_sound_sensor_.read()) + " cm");
}

void MainMenu::fan() {
  use_fan_ = true;
  screen_.lcd.print("Fan");
  fan_.write(150);
}

int8_t MainMenu::action() {
  unsigned long current_millis_ = millis();
  if (current_millis_ - prev_millis_ < UPDATE_INTERVAL_MILLIS) return 0;
  // The screen refresh every 1s -> Temp and Distance update every 1s
  prev_millis_ = current_millis_;

  screen_.lcd.clear();
  screen_.lcd.setCursor(0, 0);
  switch (idx_) {
    case 0:
      temperature();
      break;
    case 1:
      distance();
      break;
    case 3:
      fan();
      break;
  }

  return 0;
}

int8_t MainMenu::right() {
  // if we want to go to Play Song menu
  if (idx_ == 2) {
    return 1;
  } else {
    scrollable_ = false;
    return 0;
  }
}

int8_t MainMenu::left() {
  if (!scrollable_) {
    scrollable_ = true;
    prev_millis_ = -UPDATE_INTERVAL_MILLIS;
    if (use_fan_) {
      use_fan_ = false;
      fan_.write(0);
      screen_.reset_lcd();
    }
  }
  return 0;
}
