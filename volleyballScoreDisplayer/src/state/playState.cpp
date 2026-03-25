#include "state/playState.hpp"

#include "state/gameManager.hpp"
#include "state/endOfSetState.hpp"

PlayState::PlayState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager) {}

void PlayState::onEnter() {

    // Print game info
    gameInfo_.show();

}


GameState* PlayState::step(Event e) {

    // Just wait

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT: {
        // Increment point for left team and check if set is won
        GameInfo nextInfo = GameInfo(gameInfo_); // Copy current game info
        bool setWon = nextInfo.scorePoint(LEFT);

        if (setWon) {
            return new EndOfSetState(nextInfo, gameManager_); 
        } else {
            return new PlayState(nextInfo, gameManager_); 
        }
    }
    
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT: {
        // Increment point for right team and check if set is won
        GameInfo nextInfo = GameInfo(gameInfo_); // Copy current game info
        bool setWon = nextInfo.scorePoint(RIGHT);
    
        if (setWon) {
            return new EndOfSetState(nextInfo, gameManager_); 
        } else {
            return new PlayState(nextInfo, gameManager_); 
        }
    }

    default:
        // Wait for action
        return nullptr;
    }
}