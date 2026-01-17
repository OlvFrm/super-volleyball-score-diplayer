#pragma once
#include "ledStrip.hpp"

class LedDisplayBloc {
private:
  static constexpr CRGB defaultColor = CRGB::Red;
protected:
  const int size_;
  int ledOffset_;
  LedStrip* ledStrip_;
  bool attached_;
  CRGB color_;


  LedDisplayBloc(int size)
    : ledOffset_(0), size_(size), color_(defaultColor), ledStrip_(nullptr), attached_(false) {}

  bool isReady() {
    return attached_ && (ledStrip_->getSize() != 0);
  }

public:
  void addTo(LedStrip& ledStrip) {
    if (attached_) {
      Serial.println("Bloc already attached...");
      return;
    }
    ledStrip_ = &ledStrip;
    ledOffset_ = ledStrip.getSize();
    ledStrip.addBloc(size_);
    attached_ = true;
  }

  void setColor(CRGB color) {
    color_ = color;
  }
};
