#pragma once
#include "HardwareSerial.h"

#include "ledStrip.hpp"
#include "digit.hpp"
#include "serveIndicator.hpp"
#include "setCounter.hpp"
#include "state/gameState.hpp"



class ScoreDisplayer {

private:
    static LedStrip ledStrip_;

    static Digit rightUnits_;
    static Digit rightTens_;

    static Digit leftUnits_;
    static Digit leftTens_;

    static SetCounter rightSets_;
    static SetCounter leftSets_;
 
    static ServeIndicator serveIndicator_;

    /* Make the class impossible to construct. Static use only */
    ScoreDisplayer();

public:

    static void init();
    static void show();

    static void setLeftColor(CRGB color);
    static void setRightColor(CRGB color);
    static void setServeColor(CRGB color);

    static void setLeftPoints(unsigned int points);
    static void setRightPoints(unsigned int points);

    static void setLeftSets(unsigned int sets);
    static void setRightSets(unsigned int sets);

    static void setServeShow(bool show);
    
};
