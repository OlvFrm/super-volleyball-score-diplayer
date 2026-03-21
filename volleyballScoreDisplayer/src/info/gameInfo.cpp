#include "info/gameInfo.hpp"



GameInfo::GameInfo():
    scoreA_(Score()),
    scoreB_(Score()),
    teamASide_(LEFT) {};

Score GameInfo::getScore(Side side) {
    return teamASide_ == side ? scoreA_ : scoreB_;
}

Score GameInfo::getOtherScore(Side side) {
    return teamASide_ == side ? scoreB_ : scoreA_;
}


bool GameInfo::scorePoint(Side side) {

    Score scoringTeam = getScore(side);
    Score otherTeam = getOtherScore(side);
    
    scoringTeam.points_++;

    if (scoringTeam.points_ >= 25 &&
        scoringTeam.points_ >= otherTeam.points_ + 2) {
        
        scoringTeam.sets_++;
        return true;
    }

    return false;
}