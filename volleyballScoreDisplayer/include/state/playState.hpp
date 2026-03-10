#pragma once


#include "gameState.hpp"


class PlayState: public GameState {

public:

    PlayState(GameInfo info, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};