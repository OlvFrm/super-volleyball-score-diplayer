#pragma once


#include "gameState.hpp"


class EndOfGameState: public GameState {

public:

    EndOfGameState(GameInfo info, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};