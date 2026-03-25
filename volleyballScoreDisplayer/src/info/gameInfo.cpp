#include "info/gameInfo.hpp"
#include "display/scoreDisplayer.hpp"


#define DEFAULT_TEAM_A_SIDE LEFT



GameInfo::GameInfo():
    scoreA_(Score()),
    scoreB_(Score()),
    teamASide_(DEFAULT_TEAM_A_SIDE) {};


/* Getters */
Score GameInfo::getScore(Side side) const {
    return teamASide_ == side ? scoreA_ : scoreB_;
}

Score GameInfo::getOtherScore(Side side) const {
    return teamASide_ == side ? scoreB_ : scoreA_;
}

Side GameInfo::getServeSide() const { return serveSide_; }
Side GameInfo::getTeamASide() const { return teamASide_; }


/* Setters */
void GameInfo::setScore(Score score, Side side) {
    if(teamASide_ == side)
        scoreA_ = score;
    else
        scoreB_ = score;
}
void GameInfo::setServeSide(Side side) { serveSide_ = side; }
void GameInfo::setTeamASide(Side side) { teamASide_ = side; }


/* Utils */
void GameInfo::show() {
    
    /* LEFT */
    Score leftScore = getScore(LEFT);
    CRGB leftColor = teamASide_ == LEFT ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;

    ScoreDisplayer::setLeftColor(leftColor);
    ScoreDisplayer::setLeftPoints(leftScore.points_);
    ScoreDisplayer::setLeftSets(leftScore.sets_);

    /* RIGHT */
    Score rightScore = getScore(RIGHT);
    CRGB rightColor = teamASide_ == RIGHT ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;

    ScoreDisplayer::setRightColor(rightColor);
    ScoreDisplayer::setRightPoints(rightScore.points_);
    ScoreDisplayer::setRightSets(rightScore.sets_);

    /* Serve */
    CRGB serveColor = serveSide_ == teamASide_ ? DEFAULT_A_COLOR : DEFAULT_B_COLOR;
    ScoreDisplayer::setServeColor(serveColor);
    ScoreDisplayer::setServeShow(true);

    ScoreDisplayer::show();
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