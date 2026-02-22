#include "scoreDisplayer.hpp"
#include "stack.hpp"
#include "buttonHandler.hpp"

ButtonHandler buttonHandler = ButtonHandler();
ScoreDisplayer displayer = ScoreDisplayer();
Stack stack = Stack();

void setup() {
  Serial.begin(9600);
  buttonHandler.init();
  displayer.init();
}

void loop() {

  buttonHandler.checkUserInput();

  /*
  // Putting states
  for (int i = 0; i < 10; i++) {
    GameState* newState = new GameState(i, 0, false);
    stack.push(newState);
    displayer.show(stack.peek());
    Serial.println(newState->getScoreA());
    delay(2000);
  }

  // Removing states
  for (int i = 0; i < 10; i++) {
    GameState* oldState = stack.pop();
    if (oldState != nullptr) {
      displayer.show(oldState);
      Serial.println(oldState->getScoreA());
      delete oldState;
    }
    else {
      Serial.println("WTF");
    }
    delay(2000);
  }
  */
}
