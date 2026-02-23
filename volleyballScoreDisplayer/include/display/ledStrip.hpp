#pragma once

#include <FastLED.h>


class LedStrip {

private:
  int numLeds_;
  CRGB* leds_;

public:
  LedStrip();
  ~LedStrip();

  void addBloc(int blocSize);
  void init();

  int getSize();
  CRGB* getLeds();

  void show();
};
