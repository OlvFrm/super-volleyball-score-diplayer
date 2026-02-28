#include "display/scoreDisplayer.hpp"


ScoreDisplayer::ScoreDisplayer() {}

void ScoreDisplayer::init() {
    unitsA_.setColor(CRGB::Aqua);
    tensA_.setColor(CRGB::Salmon);
    unitsB_.setColor(CRGB::Tomato);
    tensB_.setColor(CRGB::Pink);

    // Choose bloc order here
    unitsA_.addTo(ledStrip_);
    tensA_.addTo(ledStrip_);
    unitsB_.addTo(ledStrip_);
    tensB_.addTo(ledStrip_);

    ledStrip_.init();
}

