#pragma once

#include "display/scoreDisplayer.hpp"
#include "input/buttonHandler.hpp"
#include "memory/stack.hpp"
#include "memory/limitedStack.hpp"


class GameState;

class GameManager {

private:

    ButtonHandler buttonHandler_;
    // Stack history_;
    LimitedStack history_;
    GameState* currentState_;

public:

    GameManager();
    ~GameManager();

    void startGame();

};