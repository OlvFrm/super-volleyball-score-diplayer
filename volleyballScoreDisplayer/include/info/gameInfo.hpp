#pragma once

#include "teamInfo.hpp"
#include "side.hpp"

/* Class that contains the information of the game. */
class GameInfo {
private:
    /* Info for team A */
    TeamInfo teamA_;
    /* Info for team B */
    TeamInfo teamB_;
    /* Info about which team is on witch side */
    Side teamASide_;

    TeamInfo getTeam(Side side);
    TeamInfo getOtherTeam(Side side);

public:
    GameInfo();

    /* Add a point to one team. Returns true if the set is won. */
    bool scorePoint(Side side);
};
