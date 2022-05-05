//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_MUSICMENU_H
#define BE_ARDUINO_MUSICMENU_H

#include <Arduino.h>

#include "Menu.h"
#include "Speaker.h"

class MusicMenu : public Menu {
 private:
  Speaker& speaker_;

 public:
  MusicMenu(Speaker& speaker);

  int8_t action() override;
  int8_t right() override;
  int8_t left() override;
};

#endif  // BE_ARDUINO_MUSICMENU_H
