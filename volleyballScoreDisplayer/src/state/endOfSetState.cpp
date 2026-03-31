#include "state/endOfSetState.hpp"
#include "state/playState.hpp"
#include "state/endOfGameState.hpp"

#include "state/gameManager.hpp"


#define SET_BLINK_DELAY   1000


EndOfSetState::EndOfSetState(GameInfo info, Side winningSide, GameManager* gameManager):
    GameState(info, true, gameManager),
    winningSide_(winningSide),
    lastBlink_(millis()),
    offset_(false) {}

void EndOfSetState::onEnter() {

    // Print game info
    gameInfo_.show();

}


GameState* EndOfSetState::step(Event e) {

    // Blink winning set LED
    long now = millis();
    if (now - lastBlink_ > SET_BLINK_DELAY) {
        offset_ = !offset_;
        ScoreDisplayer::setLeftSets(gameInfo_.getScore(winningSide_).getSets() - (offset_ ? 1 : 0));
        lastBlink_ = now;
    }

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // If the game is finished
        if (gameInfo_.getScore(winningSide_).getSets() == 3) {
            return new EndOfGameState(gameInfo_, gameManager_);
        }

        // Else start a new set
        GameInfo nextInfo = GameInfo(gameInfo_); // Copy current game info
        nextInfo.startNewSet();
        return new PlayState(nextInfo, gameManager_);
    
    default:
        // Wait for action
        return nullptr;
    }
}