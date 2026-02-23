#pragma once
#include <Arduino.h>


class Button {
private:

  static constexpr unsigned long DEBOUNCE = 20;

  uint8_t pin_;
  bool pressed_ = false;
  unsigned long pressTime_ = 0;
  unsigned long releaseTime_ = 0;

public:

  Button(uint8_t pin);

  void update(unsigned long now);

  bool isPressed() const;
  unsigned long pressTime() const;
};