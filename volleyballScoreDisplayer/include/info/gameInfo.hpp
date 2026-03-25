#pragma once

#include "score.hpp"
#include "side.hpp"


#define DEFAULT_A_COLOR     CRGB::Red
#define DEFAULT_B_COLOR     CRGB::Blue

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


    
    public:
    
    GameInfo();

    /* Getters */
    Score getScore(Side side) const;
    Score getOtherScore(Side side) const;
    Side getServeSide() const;
    Side getTeamASide() const;

    /* Puts it on displayer */
    void show();

    /* Add a point to one team. Returns true if the set is won. */
    bool scorePoint(Side side);
};
