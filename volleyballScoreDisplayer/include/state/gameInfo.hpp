#pragma once

/* Class that contains the information of the game. */
class GameInfo {
private:
    /* Score for team A */
    unsigned int scoreA_;
    /* Score for team B */
    unsigned int scoreB_;
    /* Team that serves the ball */
    bool service_;

public:
    /* Constructor that does nothing */
    GameInfo(unsigned int scoreA, unsigned int scoreB, bool service);

    /* Getters */
    unsigned int getScoreA() const;
    unsigned int getScoreB() const;
};
