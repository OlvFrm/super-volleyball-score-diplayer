#include "state/endOfSetState.hpp"
#include "state/playState.hpp"


EndOfSetState::EndOfSetState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager) {}

void EndOfSetState::onEnter() {

    // Print game info
    // TODO
    
}


GameState* EndOfSetState::step(Event e) {

    // Blink winning set LED
    // TODO

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // Start a new set
        // TODO
        return new PlayState(gameInfo_, gameManager_);
    
    default:
        // Wait for action
        return nullptr;
    }
}