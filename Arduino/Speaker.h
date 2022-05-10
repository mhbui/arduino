//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_SPEAKER_H
#define BE_ARDUINO_SPEAKER_H

#include <Arduino.h>

#include "OutputDevice.h"
#include "Pitch.h"
#include "Songs.h"

class Speaker : public OutputDevice<uint8_t> {
 private:
  const uint8_t pin_;
  void play_note(uint16_t pitch, uint8_t length);
  void play_song(const Note notes[], uint8_t song_length);
  void stop();

 public:
  Speaker(const uint8_t pin, const char* name = "Speaker");

  void write(const uint8_t& song_index) override;
};

#endif  // BE_ARDUINO_SPEAKER_H
