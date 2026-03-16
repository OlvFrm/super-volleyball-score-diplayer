#include "display/scoreDisplayer.hpp"

#define DEFAULT_A_COLOR     CRGB::Red
#define DEFAULT_B_COLOR     CRGB::Blue

ScoreDisplayer::ScoreDisplayer() {}

void ScoreDisplayer::init() {
    // Choose color here
    unitsA_.setColor(CRGB::Aqua);
    tensA_.setColor(CRGB::Salmon);
    setA_.setColor(DEFAULT_A_COLOR);
    serveA_.setColor(DEFAULT_A_COLOR);

    unitsB_.setColor(CRGB::Tomato);
    tensB_.setColor(CRGB::Pink);
    setB_.setColor(DEFAULT_B_COLOR);
    serveB_.setColor(DEFAULT_B_COLOR);

    // Choose bloc order here
    serveA_.addTo(ledStrip_);
    setA_.addTo(ledStrip_);
    unitsA_.addTo(ledStrip_);
    tensA_.addTo(ledStrip_);
    unitsB_.addTo(ledStrip_);
    tensB_.addTo(ledStrip_);
    setB_.addTo(ledStrip_);
    serveB_.addTo(ledStrip_);

    ledStrip_.init();
}


void ScoreDisplayer::show(GameInfo gameInfo) {
    // TODO when GameInfo is done
}

