//
// Created by buimi on 5/3/2022.
//

#include "Menu.h"

#include <Arduino.h>

#include "JoyStick.h"

Menu::Menu(const char* const* items, uint8_t size)
    : line_(0), idx_(0), items_(items), size_(size), scrollable_(true) {}

void Menu::scroll(Direction direction) {
  // If not scrollable , do nothing
  if (!scrollable_) return;

  //  if Scroll, move cursor and line
  if (direction == Direction::up) {
    line_ = 0;
    idx_ = (idx_ + size_ - 1) % size_;

  } else if (direction == Direction::down) {
    line_ = 1;
    idx_ = (idx_ + size_ + 1) % size_;
  }
}

const char* Menu::operator[](uint8_t idx) const { return items_[idx]; }

uint8_t Menu::current_line() const { return line_; }
uint8_t Menu::current_idx() const { return idx_; }
uint8_t Menu::size() const { return size_; }

bool Menu::scrollable() const { return scrollable_; }