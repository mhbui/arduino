//
// Created by buimi on 5/3/2022.
//

#include "Speaker.h"

#include <avr/pgmspace.h>

#include "Pitch.h"
#include "Songs.h"
// Play note with its time duration
void Speaker::play_note(uint16_t pitch, uint8_t length) {
  uint16_t note_length = 1000 / 16 * length;
  tone(pin_, pitch, note_length);
  delay(note_length * 1.3);
}
// Play the entire song
void Speaker::play_song(const Note notes[], uint8_t song_length) {
  for (uint8_t i = 0; i < song_length; ++i) {
    Note note;
    // Copy from flash to RAM
    memcpy_P(&note, &notes[i], sizeof(Note));
    play_note(note.pitch, note.length);
  }
}

void Speaker::stop() { noTone(pin_); }
// Play the song_index song in the list with the speaker
void Speaker::write(const uint8_t& song_index) {
  play_song(SongNotes[song_index], SongLengths[song_index]);
  stop();
}
