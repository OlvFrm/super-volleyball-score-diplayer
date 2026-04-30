#include "state/endOfGameState.hpp"
#include "state/playState.hpp"

#include "state/gameManager.hpp"

#define MAX_SET_NUMBER  5

unsigned int EndOfGameState::numberOfSets_ = 0;
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
    numberOfSets_ = winningSet.getSetNumber() -1; // Offset because called after winning
    winningSets_[numberOfSets_ -1] = winningSet;
}


void EndOfGameState::showNextSet() {
    winningSets_[showingSetIndex_++].show();
    if (showingSetIndex_ >= numberOfSets_) {
        showingSetIndex_ = 0;
    }
}