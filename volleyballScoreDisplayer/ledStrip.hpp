#pragma once

#include <FastLED.h>

#define LED_PIN 5


class LedStrip {

private:
  int numLeds_;
  CRGB* leds_;

public:
  LedStrip()
    : numLeds_(0), leds_(nullptr) {}

  ~LedStrip() {
    if (leds_ != nullptr) {
      free(leds_);
      leds_ = nullptr;
    }
  }

  void addBloc(int blocSize) {
    numLeds_ += blocSize;
  }

  void init() {
    // Init RGB LEDs strip
    if (leds_ != nullptr) {
      Serial.println("Must init LedStrip only once...");
      return;
    }
    if (numLeds_ == 0) {
      Serial.println("Need at least one bloc...");
      return;
    }

    leds_ = (CRGB*)calloc(numLeds_, sizeof(CRGB));
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds_, numLeds_);
    FastLED.setBrightness(10);
  }

  int getSize() {
    return numLeds_;
  }

  CRGB* getLeds() {
    return leds_;
  }

  void show() {
    FastLED.show();
  }
};
