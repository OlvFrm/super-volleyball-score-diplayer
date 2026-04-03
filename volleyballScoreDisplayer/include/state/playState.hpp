#pragma once


#include "gameState.hpp"


class PlayState: public GameState {

private:
    GameState* scorePoint(Side side);

public:

    PlayState(GameInfo info, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};