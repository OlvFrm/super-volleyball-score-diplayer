#include "HardwareSerial.h"
#pragma once

#include "ledStrip.hpp"
#include "digit.hpp"
#include "gameState.hpp"



class ScoreDisplayer {

private:
  LedStrip ledStrip_;

  Digit unitsA_;
  Digit tensA_;
  Digit unitsB_;
  Digit tensB_;

public:
  ScoreDisplayer() {}

  void init() {
    // Choose bloc order here
    unitsA_.addTo(ledStrip_);
    tensA_.addTo(ledStrip_);
    unitsB_.addTo(ledStrip_);
    tensB_.addTo(ledStrip_);

    ledStrip_.init();
  }

  void show(const GameState* gameState) {
    if (gameState == nullptr) {
      Serial.println("Null gamestate...");
    }
    unitsA_.put(gameState->getScoreA());
    ledStrip_.show();
  }
};
