#pragma once


#include "gameState.hpp"


class EndOfSetState: public GameState {

public:

    EndOfSetState(GameInfo info, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};