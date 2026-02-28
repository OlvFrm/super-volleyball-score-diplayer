#include "state/gameManager.hpp"
#include "state/startState.hpp"


GameManager::GameManager():
    currentState_(new StartState(this)) {}


GameManager::~GameManager() {
    if (currentState_ != nullptr) {
        delete currentState_;
    }
}

void GameManager::startGame() {
    displayer_.init();
    buttonHandler_.init();

    currentState_->onEnter();
    while(1) {
        Event e = buttonHandler_.checkUserInput();
        GameState* nextState = currentState_->step(e);

        if (nextState != nullptr) {
            // Save if necessary or free memory
            if (currentState_->mustBeSaved()) {
                history_.push(currentState_);
            }
            else {
                delete currentState_;
            }

            // Change state
            currentState_ = nextState;
            nextState->onEnter();
        }
    }
}