#include <Arduino.h>

#include "tools/log.hpp"
#include "state/gameManager.hpp"

GameManager game = GameManager();

void setup() {

#ifdef USE_LOGS
    Serial.begin(9600);
    LOG_INFO("Starting");
#endif

}

void loop() {
    game.startGame();
    /* Should never reach here */
}
