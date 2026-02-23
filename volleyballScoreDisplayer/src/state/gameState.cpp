#include "state/gameState.hpp"


GameState::GameState(int scoreA, int scoreB, bool service):
    scoreA_(scoreA), scoreB_(scoreB), service_(service) {}

/* Getters */
unsigned int GameState::getScoreA() const {
    return scoreA_;
}
unsigned int GameState::getScoreB() const {
    return scoreB_;
}
