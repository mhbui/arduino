//
// Created by buimi on 5/3/2022.
//

#ifndef BE_ARDUINO_SONGS_H
#define BE_ARDUINO_SONGS_H

#include <Arduino.h>
#include <avr/pgmspace.h>

#include "Pitch.h"

typedef struct Note {
  uint16_t pitch;
  uint8_t length;
} Note;

constexpr const char* SongNames[] = {
    "Happy Birthday", "Do Re Mi",  "Banh Nong Gion", "Jingle Bells",
    "Quoc ca",        "For Elise", "STHJLT"};

constexpr uint8_t NumberOfSongs = sizeof(SongNames) / sizeof(const char*);
// Definition of each Song (all the notes + its duration)
// Because the limitation of RAM memory(2 kbs), we will use PROGMEM to store it
// in the flash memory (32 kbs)
constexpr Note SongHappyBirthday[] PROGMEM = {
    {NOTE_C4, 2},  {NOTE_C4, 2}, {NOTE_D4, 4}, {NOTE_C4, 4}, {NOTE_F4, 4},
    {NOTE_E4, 8},  {NOTE_C4, 2}, {NOTE_C4, 2}, {NOTE_D4, 4}, {NOTE_C4, 4},
    {NOTE_G4, 4},  {NOTE_F4, 8}, {NOTE_C4, 2}, {NOTE_C4, 2}, {NOTE_C5, 4},
    {NOTE_A4, 4},  {NOTE_F4, 4}, {NOTE_E4, 4}, {NOTE_D4, 4}, {NOTE_AS4, 2},
    {NOTE_AS4, 2}, {NOTE_A4, 4}, {NOTE_F4, 4}, {NOTE_G4, 4}, {NOTE_F4, 8}};

constexpr Note SongDoReMi[] PROGMEM = {
    {NOTE_C4, 4}, {NOTE_D4, 4}, {NOTE_E4, 8}, {NOTE_E4, 4}, {NOTE_E4, 4},
    {NOTE_E4, 8}, {NOTE_E4, 4}, {NOTE_F4, 4}, {NOTE_G4, 8}, {NOTE_G4, 4},
    {NOTE_G4, 4}, {NOTE_G4, 8}, {NOTE_F4, 4}, {NOTE_E4, 4}, {NOTE_D4, 8},
    {NOTE_D4, 4}, {NOTE_D4, 4}, {NOTE_D4, 8}, {NOTE_E4, 4}, {NOTE_D4, 4},
    {NOTE_C4, 8}, {NOTE_C4, 4}, {NOTE_C4, 4}, {NOTE_C4, 8}};

constexpr Note SongBanhNongGion[] PROGMEM = {
    {NOTE_E4, 4}, {NOTE_D4, 4}, {NOTE_C4, 8}, {NOTE_E4, 4}, {NOTE_D4, 4},
    {NOTE_C4, 8}, {NOTE_C4, 4}, {NOTE_C4, 4}, {NOTE_D4, 4}, {NOTE_D4, 4},
    {NOTE_E4, 4}, {NOTE_D4, 4}, {NOTE_C4, 8}};

constexpr Note SongJingleBells[] PROGMEM = {
    {NOTE_E4, 4},  {NOTE_E4, 4}, {NOTE_E4, 8}, {NOTE_E4, 4}, {NOTE_E4, 4},
    {NOTE_E4, 8},  {NOTE_E4, 4}, {NOTE_G4, 4}, {NOTE_C4, 6}, {NOTE_D4, 2},
    {NOTE_E4, 12}, {NOTE_F4, 4}, {NOTE_F4, 4}, {NOTE_F4, 4}, {NOTE_F4, 4},
    {NOTE_F4, 4},  {NOTE_E4, 4}, {NOTE_E4, 4}, {NOTE_E4, 4}, {NOTE_E4, 4},
    {NOTE_D4, 4},  {NOTE_D4, 4}, {NOTE_E4, 4}, {NOTE_D4, 8}, {NOTE_G4, 8},
    {NOTE_E4, 4},  {NOTE_E4, 4}, {NOTE_E4, 8}, {NOTE_E4, 4}, {NOTE_E4, 4},
    {NOTE_E4, 8},  {NOTE_E4, 4}, {NOTE_G4, 4}, {NOTE_C4, 6}, {NOTE_D4, 2},
    {NOTE_E4, 12}, {NOTE_F4, 4}, {NOTE_F4, 4}, {NOTE_F4, 4}, {NOTE_F4, 4},
    {NOTE_F4, 4},  {NOTE_E4, 4}, {NOTE_E4, 4}, {NOTE_E4, 4}, {NOTE_G4, 4},
    {NOTE_G4, 4},  {NOTE_F4, 4}, {NOTE_D4, 4}, {NOTE_C4, 16}};

constexpr Note SongQuocCa[] PROGMEM = {
    {NOTE_C4, 2},  {NOTE_D4, 6},  {NOTE_C4, 2},  {NOTE_F4, 8},  {NOTE_F4, 16},
    {NOTE_G4, 4},  {NOTE_F4, 4},  {NOTE_A4, 8},  {NOTE_A4, 16}, {NOTE_G4, 4},
    {NOTE_F4, 4},  {NOTE_D4, 8},  {NOTE_F4, 8},  {NOTE_F4, 4},  {NOTE_D4, 4},
    {NOTE_C4, 4},  {NOTE_A3, 4},  {NOTE_C4, 16}, {NOTE_0, 4},   {NOTE_F4, 4},
    {NOTE_G4, 4},  {NOTE_A4, 8},  {NOTE_A4, 8},  {NOTE_A4, 8},  {NOTE_G4, 4},
    {NOTE_F4, 4},  {NOTE_C5, 16}, {NOTE_0, 4},   {NOTE_A4, 4},  {NOTE_F4, 4},
    {NOTE_G4, 8},  {NOTE_G4, 8},  {NOTE_A4, 8},  {NOTE_E4, 4},  {NOTE_C4, 4},
    {NOTE_F4, 16}, {NOTE_0, 4},   {NOTE_A4, 4},  {NOTE_B4, 4},  {NOTE_C5, 8},
    {NOTE_C5, 8},  {NOTE_D5, 12}, {NOTE_C5, 4},  {NOTE_A4, 16}, {NOTE_A4, 12},
    {NOTE_G4, 4},  {NOTE_F4, 8},  {NOTE_C4, 8},  {NOTE_E4, 8},  {NOTE_E4, 4},
    {NOTE_G4, 4},  {NOTE_F4, 24}, {NOTE_A4, 4},  {NOTE_B4, 4},  {NOTE_C5, 8},
    {NOTE_C5, 8},  {NOTE_D5, 12}, {NOTE_C5, 4},  {NOTE_A4, 16}, {NOTE_A4, 12},
    {NOTE_G4, 4},  {NOTE_F4, 8},  {NOTE_F4, 8},  {NOTE_C4, 16}, {NOTE_C5, 16},
    {NOTE_A4, 24}, {NOTE_F4, 8},  {NOTE_D5, 16}, {NOTE_C5, 20}, {NOTE_A4, 4},
    {NOTE_G4, 4},  {NOTE_C4, 4},  {NOTE_G4, 8},  {NOTE_G4, 16}, {NOTE_A4, 8},
    {NOTE_F4, 20}};

constexpr Note SongForElise[] PROGMEM = {
    {NOTE_E5, 3}, {NOTE_DS5, 3}, {NOTE_E5, 3},  {NOTE_DS5, 3}, {NOTE_E5, 3},
    {NOTE_B4, 3}, {NOTE_D5, 3},  {NOTE_C5, 3},  {NOTE_A4, 6},  {NOTE_0, 3},
    {NOTE_C4, 3}, {NOTE_E4, 3},  {NOTE_A4, 3},  {NOTE_B4, 6},  {NOTE_0, 3},
    {NOTE_E4, 3}, {NOTE_GS4, 3}, {NOTE_B4, 3},  {NOTE_C5, 6},  {NOTE_0, 3},
    {NOTE_E4, 3}, {NOTE_E5, 3},  {NOTE_DS5, 3}, {NOTE_E5, 3},  {NOTE_DS5, 3},
    {NOTE_E5, 3}, {NOTE_B4, 3},  {NOTE_D5, 3},  {NOTE_C5, 3},  {NOTE_A4, 6},
    {NOTE_0, 3},  {NOTE_C4, 3},  {NOTE_E4, 3},  {NOTE_A4, 3},  {NOTE_B4, 6},
    {NOTE_0, 3},  {NOTE_D4, 3},  {NOTE_C5, 3},  {NOTE_B4, 3},  {NOTE_A4, 8}};

constexpr Note SongSTHJLT[] PROGMEM = {
    {NOTE_D4, 8},   {NOTE_D4, 4},  {NOTE_A4, 4},   {NOTE_D4, 8},
    {NOTE_D4, 4},   {NOTE_A4, 4},  {NOTE_D4, 8},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_D4, 4},  {NOTE_A4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_D4, 8},  {NOTE_D4, 4},   {NOTE_A4, 4},
    {NOTE_D4, 8},   {NOTE_D4, 4},  {NOTE_A4, 4},   {NOTE_D4, 12},
    {NOTE_D4, 4},   {NOTE_D4, 4},  {NOTE_D4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_G3, 12}, {NOTE_D4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_E4, 4},  {NOTE_CS4, 4},  {NOTE_D4, 12},
    {NOTE_D4, 4},   {NOTE_D4, 4},  {NOTE_D4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_G3, 12}, {NOTE_D4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_FS4, 4}, {NOTE_D4, 4},   {NOTE_D4, 12},
    {NOTE_FS4, 4},  {NOTE_FS4, 4}, {NOTE_FS4, 4},  {NOTE_FS4, 4},
    {NOTE_FS4, 4},  {NOTE_G4, 12}, {NOTE_G4, 4},   {NOTE_G4, 4},
    {NOTE_E4, 4},   {NOTE_E4, 4},  {NOTE_FS4, 4},  {NOTE_FS4, 16},
    {NOTE_0, 4},    {NOTE_D4, 4},  {NOTE_D4, 4},   {NOTE_FS4, 4},
    {NOTE_FS4, 4},  {NOTE_E4, 4},  {NOTE_E4, 4},   {NOTE_E4, 4},
    {NOTE_E4, 4},   {NOTE_E4, 4},  {NOTE_E4, 4},   {NOTE_D4, 4},
    {NOTE_D4, 8},   {NOTE_D4, 4},  {NOTE_D4, 4},   {NOTE_FS4, 4},
    {NOTE_A4, 4},   {NOTE_A4, 4},  {NOTE_A4, 4},   {NOTE_B4, 12},
    {NOTE_B4, 4},   {NOTE_B4, 4},  {NOTE_A4, 4},   {NOTE_A4, 4},
    {NOTE_G4, 4},   {NOTE_FS4, 8}, {NOTE_FS4, 4},  {NOTE_FS4, 4},
    {NOTE_FS4, 4},  {NOTE_FS4, 4}, {NOTE_FS4, 4},  {NOTE_A4, 4},
    {NOTE_A4, 4},   {NOTE_E4, 4},  {NOTE_E4, 4},   {NOTE_E4, 4},
    {NOTE_E4, 4},   {NOTE_E4, 4},  {NOTE_G4, 4},   {NOTE_FS4, 4},
    {NOTE_FS4, 12}, {NOTE_D4, 4},  {NOTE_FS4, 4},  {NOTE_A4, 4},
    {NOTE_A4, 4},   {NOTE_A4, 4},  {NOTE_B4, 12},  {NOTE_B4, 4},
    {NOTE_B4, 4},   {NOTE_A4, 4},  {NOTE_A4, 4},   {NOTE_G4, 4},
    {NOTE_FS4, 12}, {NOTE_FS4, 4}, {NOTE_FS4, 4},  {NOTE_FS4, 4},
    {NOTE_FS4, 4},  {NOTE_FS4, 4}, {NOTE_G4, 6},   {NOTE_E4, 6},
    {NOTE_E4, 4},   {NOTE_E4, 4},  {NOTE_E4, 4},   {NOTE_G4, 4},
    {NOTE_FS4, 4},  {NOTE_FS4, 8}, {NOTE_D4, 4},   {NOTE_FS4, 4},
    {NOTE_FS4, 4},  {NOTE_E4, 4},  {NOTE_E4, 4},   {NOTE_E4, 8},
    {NOTE_D4, 8},   {NOTE_D4, 2},  {NOTE_E4, 2},   {NOTE_FS4, 4},
    {NOTE_D4, 2},   {NOTE_E4, 2},  {NOTE_FS4, 16}, {NOTE_D4, 2},
    {NOTE_E4, 2},   {NOTE_FS4, 4}, {NOTE_E4, 4},   {NOTE_E4, 8},
    {NOTE_D4, 12},  {NOTE_D4, 2},  {NOTE_E4, 2},   {NOTE_FS4, 4},
    {NOTE_D4, 2},   {NOTE_E4, 2},  {NOTE_FS4, 16}, {NOTE_D4, 4},
    {NOTE_D4, 4},   {NOTE_FS4, 4}, {NOTE_FS4, 4},  {NOTE_E4, 4},
    {NOTE_E4, 4},   {NOTE_E4, 8},  {NOTE_D4, 8},   {NOTE_D5, 2},
    {NOTE_E5, 2},   {NOTE_FS5, 4}, {NOTE_D5, 2},   {NOTE_E5, 2},
    {NOTE_FS5, 16}, {NOTE_D5, 2},  {NOTE_E5, 2},   {NOTE_FS5, 4},
    {NOTE_E5, 6},   {NOTE_D5, 18}, {NOTE_D5, 2},   {NOTE_E5, 2},
    {NOTE_FS5, 4},  {NOTE_D5, 2},  {NOTE_E5, 2},   {NOTE_FS5, 8},
    {NOTE_FS5, 4},  {NOTE_B4, 4},  {NOTE_D5, 4},   {NOTE_FS5, 4},
    {NOTE_FS5, 4},  {NOTE_E5, 4},  {NOTE_E5, 4},   {NOTE_E5, 4},
    {NOTE_D5, 4}};

// Song list
constexpr const Note* SongNotes[NumberOfSongs] = {
    SongHappyBirthday, SongDoReMi,   SongBanhNongGion, SongJingleBells,
    SongQuocCa,        SongForElise, SongSTHJLT};

constexpr uint8_t SongLengths[NumberOfSongs] = {
    sizeof(SongHappyBirthday) / sizeof(Note),
    sizeof(SongDoReMi) / sizeof(Note),
    sizeof(SongBanhNongGion) / sizeof(Note),
    sizeof(SongJingleBells) / sizeof(Note),
    sizeof(SongQuocCa) / sizeof(Note),
    sizeof(SongForElise) / sizeof(Note),
    sizeof(SongSTHJLT) / sizeof(Note)};

#endif  // BE_ARDUINO_SONGS_H
