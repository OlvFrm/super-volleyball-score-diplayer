#include <Arduino.h>

#include "state/gameManager.hpp"

GameManager game = GameManager();

void setup() {
    Serial.begin(9600);
}

void loop() {
    game.startGame();
    /* Should never reach here */
}
