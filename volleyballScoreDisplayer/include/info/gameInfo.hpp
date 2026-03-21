#pragma once

#include "score.hpp"
#include "side.hpp"

/* Class that contains the information of the game. */
class GameInfo {
private:
    /* Info for team A */
    Score scoreA_;
    /* Info for team B */
    Score scoreB_;
    /* Info about which team has the serve */
    Side serveSide_;
    /* Info about which team is on witch side */
    Side teamASide_;


    Score getScore(Side side);
    Score getOtherScore(Side side);

public:

    GameInfo();

    /* Add a point to one team. Returns true if the set is won. */
    bool scorePoint(Side side);
};
