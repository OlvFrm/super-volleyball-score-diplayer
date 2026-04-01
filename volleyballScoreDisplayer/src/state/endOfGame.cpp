#include "state/endOfGameState.hpp"
#include "state/playState.hpp"

#include "state/gameManager.hpp"

#define MAX_SET_NUMBER  5

unsigned int EndOfGameState::winningSetIndex_ = 0;
GameInfo EndOfGameState::winningSets_ [MAX_SET_NUMBER];


EndOfGameState::EndOfGameState(GameInfo info, GameManager* gameManager):
    GameState(info, true, gameManager),
    showingSetIndex_(0) {}



void EndOfGameState::onEnter() {
    showNextSet();
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
        showNextSet();
        return nullptr;
    default:
        // Wait for action
        return nullptr;
    }
}


void EndOfGameState::addWinningSet(GameInfo winningSet) {
    if (winningSetIndex_ < MAX_SET_NUMBER) {
        winningSets_[winningSetIndex_++] = winningSet;
    }
}


void EndOfGameState::showNextSet() {
    winningSets_[showingSetIndex_++].show();
    if (showingSetIndex_ >= winningSetIndex_) {
        showingSetIndex_ = 0;
    }
}