#include "scoreDisplayer.hpp"

ScoreDisplayer displayer = ScoreDisplayer();
GameState state = GameState();

void setup() {
  Serial.begin(9600);
  displayer.init();
}

void loop() {
  Serial.println(state.score_);
  displayer.show(state);
  state.score_ = (state.score_ + 1) % 10;
  delay(2000);
}
