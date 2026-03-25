#pragma once
#include "ledStrip.hpp"

class LedDisplayBloc {

  protected:
  const int size_;
  int ledOffset_;
  LedStrip* ledStrip_;
  bool attached_;
  CRGB color_;


  LedDisplayBloc(int size);
  bool isReady();

public:
  void addTo(LedStrip& ledStrip);
  void setColor(CRGB color);
};
