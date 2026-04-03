#pragma once


#include "gameState.hpp"


class EndOfSetState: public GameState {

private:
    Side winningSide_;
    long lastBlink_;
    bool offset_;

public:

    EndOfSetState(GameInfo info, Side winningSide, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

};