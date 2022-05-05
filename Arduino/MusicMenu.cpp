//
// Created by buimi on 5/3/2022.
//

#include "MusicMenu.h"

#include <Arduino.h>

#include "Songs.h"

MusicMenu::MusicMenu(Speaker& speaker)
    : Menu(SongNames, NumberOfSongs), speaker_(speaker) {}

int8_t MusicMenu::action() { return 0; }

int8_t MusicMenu::right() {
  speaker_.write(idx_);
  return 0;
}

int8_t MusicMenu::left() { return -1; }
