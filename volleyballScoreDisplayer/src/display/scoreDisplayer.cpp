#include "display/scoreDisplayer.hpp"

#define DEFAULT_A_COLOR     CRGB::Red
#define DEFAULT_B_COLOR     CRGB::Blue

ScoreDisplayer::ScoreDisplayer() {}

void ScoreDisplayer::init() {
    // Choose color here
    rightUnits_.setColor(CRGB::Aqua);
    rightTens_.setColor(CRGB::Salmon);
    rightSet_.setColor(DEFAULT_A_COLOR);
    rightServe_.setColor(DEFAULT_A_COLOR);

    leftUnits_.setColor(CRGB::Tomato);
    leftTens_.setColor(CRGB::Pink);
    leftSet_.setColor(DEFAULT_B_COLOR);
    leftServe_.setColor(DEFAULT_B_COLOR);

    // Choose bloc order here
    rightServe_.addTo(ledStrip_);
    rightSet_.addTo(ledStrip_);
    rightUnits_.addTo(ledStrip_);
    rightTens_.addTo(ledStrip_);
    leftUnits_.addTo(ledStrip_);
    leftTens_.addTo(ledStrip_);
    leftSet_.addTo(ledStrip_);
    leftServe_.addTo(ledStrip_);

    ledStrip_.init();
}


void ScoreDisplayer::show(GameInfo gameInfo) {
    // TODO when GameInfo is done
}

