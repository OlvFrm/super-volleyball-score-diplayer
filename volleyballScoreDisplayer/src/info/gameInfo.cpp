#include "info/gameInfo.hpp"



GameInfo::GameInfo():
    teamA_(TeamInfo()),
    teamB_(TeamInfo()),
    teamASide_(LEFT) {};

TeamInfo GameInfo::getTeam(Side side) {
    return teamASide_ == side ? teamA_ : teamB_;
}

TeamInfo GameInfo::getOtherTeam(Side side) {
    return teamASide_ == side ? teamB_ : teamA_;
}


bool GameInfo::scorePoint(Side side) {

    TeamInfo scoringTeam = getTeam(side);
    TeamInfo otherTeam = getOtherTeam(side);
    
    scoringTeam.score_++;

    if (scoringTeam.score_ >= 25 &&
        scoringTeam.score_ >= otherTeam.score_ + 2) {
        
        scoringTeam.set_++;
        return true;
    }

    return false;
}