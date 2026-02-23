#include "input/button.hpp"


Button::Button(uint8_t pin): pin_(pin) {}

void Button::update(unsigned long now) {
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

bool Button::isPressed() const {
    return pressed_;
}
unsigned long Button::pressTime() const {
    return pressTime_;
}