#include "state/playState.hpp"


PlayState::PlayState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager) {}

void PlayState::onEnter() {

    // Print game info
    // TODO

}


GameState* PlayState::step(Event e) {

    // Just wait

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
        // Increment point for left team and check if set is won
        // TODO
        return new PlayState(gameInfo_, gameManager_); // Or EndOfSetState
    
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // Increment point for right team and check if set is won
        // TODO
        return new PlayState(gameInfo_, gameManager_);
    
    default:
        // Wait for action
        return nullptr;
    }
}