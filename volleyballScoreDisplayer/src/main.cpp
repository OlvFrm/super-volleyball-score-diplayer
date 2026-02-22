#include <Arduino.h>

#include "display/scoreDisplayer.hpp"
#include "memory/stack.hpp"
#include "input/buttonHandler.hpp"

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
}
