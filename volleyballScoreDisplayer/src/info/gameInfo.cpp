#include "info/gameInfo.hpp"

#define DEFAULT_TEAM_A_SIDE LEFT

GameInfo::GameInfo():
    scoreA_(Score()),
    scoreB_(Score()),
    teamASide_(DEFAULT_TEAM_A_SIDE) {};


Score GameInfo::getScore(Side side) const {
    return teamASide_ == side ? scoreA_ : scoreB_;
}

Score GameInfo::getOtherScore(Side side) const {
    return teamASide_ == side ? scoreB_ : scoreA_;
}

Side GameInfo::getServeSide() const { return serveSide_; }
Side GameInfo::getTeamASide() const { return teamASide_; }


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