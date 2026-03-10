#include "state/startState.hpp"
#include "state/playState.hpp"

StartState::StartState(GameManager* gameManager):
    GameState(GameInfo(0, 0, false), true, gameManager) {}

void StartState::onEnter() {

    // Print game info (all zeros)
    // TODO

}

GameState* StartState::step(Event e) {
    
    // Blink serve LEDs
    // TODO

    // Check event
    switch (e) {
    case Event::LEFT_SHORT:
    case Event::LEFT_LONG:
    case Event::LEFT_REPEAT:
        // Set serve to left team and change state
        // TODO
        return new PlayState(gameInfo_, gameManager_);
    
    case Event::RIGHT_SHORT:
    case Event::RIGHT_LONG:
    case Event::RIGHT_REPEAT:
        // Set serve to right team and change state
        // TODO
        return new PlayState(gameInfo_, gameManager_);
    
    default:
        // Wait for action
        return nullptr;
    }
    
}