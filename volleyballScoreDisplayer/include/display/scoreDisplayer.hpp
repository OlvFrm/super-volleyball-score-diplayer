#pragma once
#include "HardwareSerial.h"

#include "ledStrip.hpp"
#include "digit.hpp"
#include "state/gameState.hpp"



class ScoreDisplayer {

private:
  LedStrip ledStrip_;

  Digit unitsA_;
  Digit tensA_;
  Digit unitsB_;
  Digit tensB_;

public:
  ScoreDisplayer();

  void init();
  
  void show(const GameState* gameState);
};
