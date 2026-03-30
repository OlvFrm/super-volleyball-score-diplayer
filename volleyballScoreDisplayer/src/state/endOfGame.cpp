#include "state/endOfGameState.hpp"
#include "state/playState.hpp"

#include "state/gameManager.hpp"

EndOfGameState::EndOfGameState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager) {}

void EndOfGameState::onEnter() {

    // Print game info
    gameInfo_.show();
    
}


GameState* EndOfGameState::step(Event e) {

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // TODO show game recap
    default:
        // Wait for action
        return nullptr;
    }
}