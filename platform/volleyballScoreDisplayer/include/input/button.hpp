#pragma once

class Button {
private:

  static constexpr unsigned long DEBOUNCE = 20;

  uint8_t pin_;
  bool pressed_ = false;
  unsigned long pressTime_ = 0;
  unsigned long releaseTime_ = 0;

public:

  Button(uint8_t pin)
    : pin_(pin) {}

  void update(unsigned long now) {
    bool isDown = digitalRead(pin_) == LOW;

    if (isDown && !pressed_ && (now - releaseTime_) > DEBOUNCE) {
      pressed_ = true;
      pressTime_ = now;
    }

    if (!isDown && pressed_ && (now - pressTime_) > DEBOUNCE) {
      pressed_ = false;
      releaseTime_ = now;
    }
  }

  bool isPressed() const {
    return pressed_;
  }
  unsigned long pressTime() const {
    return pressTime_;
  }
};