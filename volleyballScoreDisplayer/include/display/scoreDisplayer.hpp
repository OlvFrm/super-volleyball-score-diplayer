#pragma once
#include "HardwareSerial.h"

#include "ledStrip.hpp"
#include "digit.hpp"
#include "serveIndicator.hpp"
#include "setCounter.hpp"
#include "state/gameState.hpp"



class ScoreDisplayer {

private:
    LedStrip ledStrip_;

    Digit rightUnits_;
    Digit rightTens_;

    Digit leftUnits_;
    Digit leftTens_;

    SetCounter rightSet_;
    SetCounter leftSet_;

    ServeIndicator rightServe_;
    ServeIndicator leftServe_;

public:
    ScoreDisplayer();

    void init();
    void show(GameInfo gameInfo);
};
