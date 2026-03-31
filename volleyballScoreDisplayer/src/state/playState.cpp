#include "state/playState.hpp"

#include "state/gameManager.hpp"
#include "state/endOfSetState.hpp"

PlayState::PlayState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager) {}

void PlayState::onEnter() {

    // Print game info
    gameInfo_.show();

}


GameState* PlayState::scorePoint(Side side) {
    GameInfo nextInfo = GameInfo(gameInfo_); // Copy current game info
    bool setWon = nextInfo.scorePoint(side);

    if (setWon) {
        return new EndOfSetState(nextInfo, side, gameManager_); 
    }
    return new PlayState(nextInfo, gameManager_); 
}

GameState* PlayState::step(Event e) {

    // Just wait

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT: {
        return scorePoint(LEFT);        
    }
    
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT: {
        return scorePoint(RIGHT);
    }

    default:
        // Wait for action
        return nullptr;
    }
}