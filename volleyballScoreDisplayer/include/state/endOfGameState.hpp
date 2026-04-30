#pragma once


#include "gameState.hpp"



class EndOfGameState: public GameState {

private:
    static unsigned int numberOfSets_;
    static GameInfo winningSets_[];

    unsigned int showingSetIndex_;

public:

    EndOfGameState(GameInfo info, GameManager* gameManager);

    void onEnter() override;
    GameState* step(Event e) override;

    static void addWinningSet(GameInfo winningSet);
    void showNextSet();

};