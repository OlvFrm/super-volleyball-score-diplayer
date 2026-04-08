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
    ScoreDisplayer::init();
    buttonHandler_.init();

    currentState_->onEnter();
    while(1) {
        Event e = buttonHandler_.checkUserInput();
        GameState* nextState;

        // Handle common behaviour
        switch (e) {
            case Event::DOUBLE_SHORT: {
                // Ctrl-Z
                nextState = history_.pop();
                currentState_->setSaveMode(false);
                break;
            }
            
            case Event::DOUBLE_LONG: {
                // Full reset
                history_.reset();
                nextState = new StartState(this);
                currentState_->setSaveMode(false);
                break;
            }

            default:
                nextState = currentState_->step(e);
                break;
            }

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
