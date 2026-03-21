#include "display/scoreDisplayer.hpp"

#define DEFAULT_A_COLOR     CRGB::Red
#define DEFAULT_B_COLOR     CRGB::Blue

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


void ScoreDisplayer::show(GameInfo gameInfo) {
    
    /* LEFT */
    Score leftScore = gameInfo.getScore(LEFT);
    CRGB leftColor = gameInfo.getTeamASide() == LEFT ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;

    leftUnits_.put(leftScore.getPoints() % 10, leftColor);
    leftTens_.put(leftScore.getPoints() / 10, leftColor);
    leftSets_.put(leftScore.getSets(), leftColor);

    /* RIGHT */
    Score rightScore = gameInfo.getScore(RIGHT);
    CRGB rightColor = gameInfo.getTeamASide() == RIGHT ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;

    rightUnits_.put(rightScore.getPoints() % 10, rightColor);
    rightTens_.put(rightScore.getPoints() / 10, rightColor);
    rightSets_.put(rightScore.getSets(), rightColor);

    /* Serve */
    CRGB serveColor = gameInfo.getServeSide() == gameInfo.getTeamASide() ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;
    serveIndicator_.put(serveColor);

    ledStrip_.show();
}

