#include "info/score.hpp"

Score::Score():
    points_(0),
    sets_(0) {}

unsigned int Score::getPoints() const { return points_; }
unsigned int Score::getSets() const { return sets_; }