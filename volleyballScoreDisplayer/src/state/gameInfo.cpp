#include "state/gameInfo.hpp"


GameInfo::GameInfo(unsigned int scoreA, unsigned int scoreB, bool service):
    scoreA_(scoreA), scoreB_(scoreB), service_(service) {}

unsigned int GameInfo::getScoreA() const { return scoreA_; }
unsigned int GameInfo::getScoreB() const { return scoreB_; }