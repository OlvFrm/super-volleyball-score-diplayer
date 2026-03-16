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

    Digit unitsA_;
    Digit tensA_;
    Digit unitsB_;
    Digit tensB_;

    SetCounter setA_;
    SetCounter setB_;

    ServeIndicator serveA_;
    ServeIndicator serveB_;

public:
    ScoreDisplayer();

    void init();
    void show(GameInfo gameInfo);
};
