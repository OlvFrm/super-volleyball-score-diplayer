#include "state/gameState.hpp"


GameState::GameState(GameInfo info, bool mustBeSaved, GameManager* gameManager):
    gameInfo_(info), mustBeSaved_(mustBeSaved), gameManager_(gameManager) {}

GameState::~GameState() {}

bool GameState::mustBeSaved() const { return mustBeSaved_; }
void GameState::setSaveMode(bool mustBeSaved) { mustBeSaved_ = mustBeSaved; }