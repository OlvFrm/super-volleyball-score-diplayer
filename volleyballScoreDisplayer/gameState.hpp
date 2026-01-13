#pragma once

/* Class that contains the state of the game. 
  For now just for debugging purposes
*/
class GameState {
private:
  /* Score for team A */
  unsigned int scoreA_;
  /* Score for team B */
  unsigned int scoreB_;
  /* Team that serves the ball */
  bool service_;

public:
  /* Constructor that does nothing */
  GameState(int scoreA, int scoreB, bool service)
    : scoreA_(scoreA), scoreB_(scoreB), service_(service) {}

  /* Getters */
  unsigned int getScoreA() {
    return scoreA_;
  }
  unsigned int getScoreB() {
    return scoreB_;
  }
};
