#pragma once


#include "gameState.hpp"




class StartState: public GameState {

public:
    StartState(GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;
};