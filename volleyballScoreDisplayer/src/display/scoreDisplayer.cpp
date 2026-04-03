#include "display/scoreDisplayer.hpp"



LedStrip ScoreDisplayer::ledStrip_ = LedStrip();
Digit ScoreDisplayer::rightUnits_ = Digit();
Digit ScoreDisplayer::rightTens_ = Digit();
Digit ScoreDisplayer::leftUnits_ = Digit();
Digit ScoreDisplayer::leftTens_ = Digit();
SetCounter ScoreDisplayer::rightSets_ = SetCounter();
SetCounter ScoreDisplayer::leftSets_ = SetCounter();
ServeIndicator ScoreDisplayer::serveIndicator_ = ServeIndicator();


ScoreDisplayer::ScoreDisplayer() {}

void ScoreDisplayer::init() {

    // Choose bloc order here
    rightSets_.addTo(ledStrip_);
    rightUnits_.addTo(ledStrip_);
    rightTens_.addTo(ledStrip_);
    serveIndicator_.addTo(ledStrip_);
    leftUnits_.addTo(ledStrip_);
    leftTens_.addTo(ledStrip_);
    leftSets_.addTo(ledStrip_);

    ledStrip_.init();
}

void ScoreDisplayer::show() {
    ledStrip_.show();
}


void ScoreDisplayer::setLeftColor(CRGB color) {
    leftUnits_.setColor(color);
    leftTens_.setColor(color);
    leftSets_.setColor(color);
}
void ScoreDisplayer::setRightColor(CRGB color) {
    rightUnits_.setColor(color);
    rightTens_.setColor(color);
    rightSets_.setColor(color);
}
void ScoreDisplayer::setServeColor(CRGB color) {
    serveIndicator_.setColor(color);
}

void ScoreDisplayer::setLeftPoints(unsigned int points) {
    leftUnits_.put(points % 10);
    leftTens_.put(points / 10);
}
void ScoreDisplayer::setRightPoints(unsigned int points) {
    rightUnits_.put(points % 10);
    rightTens_.put(points / 10);
}

void ScoreDisplayer::setLeftSets(unsigned int sets) {
    leftSets_.put(sets);
}
void ScoreDisplayer::setRightSets(unsigned int sets) {
    rightSets_.put(sets);
}

void ScoreDisplayer::setServeShow(bool show) {
    serveIndicator_.put(show);
}

