#include "state/startState.hpp"
#include "state/playState.hpp"

#include "state/gameManager.hpp"


#define SERVE_BLINK_DELAY   1000

StartState::StartState(GameManager* gameManager):
    GameState(GameInfo(), true, gameManager),
    lastBlink_(millis()),
    useTeamAColor_(true) {}

void StartState::onEnter() {

    // Print game info (all zeros)
    gameInfo_.show();

}

GameState* StartState::selectServe(Side side) {

    GameInfo newInfo = GameInfo(gameInfo_);
    newInfo.setServeSide(side, true);

    return new PlayState(newInfo, gameManager_);
}

GameState* StartState::step(Event e) {
    
    // Blink serve LEDs
    long now = millis();
    if (now - lastBlink_ > SERVE_BLINK_DELAY) {
        
        useTeamAColor_ = !useTeamAColor_;
        ScoreDisplayer::setServeColor(useTeamAColor_ ? DEFAULT_A_COLOR : DEFAULT_B_COLOR);
        ScoreDisplayer::setServeShow(true);

        lastBlink_ = now;
    }

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
        // Set serve to left team and change state
        return selectServe(LEFT);
    
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // Set serve to right team and change state
        return selectServe(RIGHT);
    
    default:
        // Wait for action
        return nullptr;
    } 
}