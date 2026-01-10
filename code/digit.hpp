#pragma once
#include "HardwareSerial.h"
#include "ledDisplayBloc.hpp"

#define NUM_LEDS_PER_SEGMENT 2

/* Assuming segments are arranged like:
  --2--
 |     |
 1     3
 |     |
  --4--
 |     |
 5     7
 |     |
  --6--
 */


class Digit : public LedDisplayBloc {

public:
  Digit()
    : LedDisplayBloc(7 * NUM_LEDS_PER_SEGMENT) {}

  void put(int digit) {
    if (!isReady()) {
      Serial.println("Bloc error...");
      return;
    }
    if (digit < 0 || digit > 9) {
      Serial.println("Incorrect digit...");
      return;
    }

    int currentIndex = ledOffset_;
    bool segmentPatterns[10][7] = {
      { 1, 1, 1, 0, 1, 1, 1 },  // 0
      { 0, 0, 1, 0, 0, 0, 1 },  // 1
      { 0, 1, 1, 1, 1, 1, 0 },  // 2
      { 0, 1, 1, 1, 0, 1, 1 },  // 3
      { 1, 0, 1, 1, 0, 0, 1 },  // 4
      { 1, 1, 0, 1, 0, 1, 1 },  // 5
      { 1, 1, 0, 1, 1, 1, 1 },  // 6
      { 0, 1, 1, 0, 0, 0, 1 },  // 7
      { 1, 1, 1, 1, 1, 1, 1 },  // 8
      { 1, 1, 1, 1, 0, 1, 1 },  // 9
    };

    // Looping for all segments
    for (int segment = 0; segment < 7; segment++) {

      CRGB color = segmentPatterns[digit][segment] == true ? CRGB::Red : CRGB::Black;

      // Looping for all leds in the segment
      for (int led = 0; led < NUM_LEDS_PER_SEGMENT; led++) {
        ledStrip_->getLeds()[currentIndex] = color;
        currentIndex++;
      }
    }
  }
};
