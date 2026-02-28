#include "state/startState.hpp"


StartState::StartState(GameManager* gameManager):
    GameState(GameInfo(0, 0, false), true, gameManager) {}

void StartState::onEnter() {
    // TODO
}


GameState* StartState::step(Event e) {
    // TODO
    return nullptr;
}