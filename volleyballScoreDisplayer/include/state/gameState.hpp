#pragma once

#include "gameInfo.hpp"
#include "event.hpp"

class GameManager;


/* Class that contains the state of the game. */
class GameState {

protected:
    const GameInfo gameInfo_;
    const bool mustBeSaved_;
    const GameManager* gameManager_;

    GameState(GameInfo info, bool mustBeSaved, GameManager* gameManager);
    
public:
    virtual ~GameState();

    virtual void onEnter() = 0;
    virtual GameState* step(Event e) = 0;

    bool mustBeSaved() const;
};
