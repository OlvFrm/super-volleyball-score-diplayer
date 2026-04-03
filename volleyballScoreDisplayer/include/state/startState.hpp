#pragma once


#include "gameState.hpp"


class StartState: public GameState {

private:
    long lastBlink_;
    bool useTeamAColor_;

    GameState* selectServe(Side side);

public:

    StartState(GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};