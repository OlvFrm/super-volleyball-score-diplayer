#include "display/serveIndicator.hpp"

#define SERVE_LED_NUMBER    1

ServeIndicator::ServeIndicator():
    LedDisplayBloc(SERVE_LED_NUMBER) {}

void ServeIndicator::put(bool show) {
    if (!isReady()) {
        Serial.println("Bloc error...");
        return;
    }

    for (int i = 0; i < SERVE_LED_NUMBER; i++) {
        ledStrip_->getLeds()[ledOffset_ + i] = show ? color_ : CRGB::Black;
    }
}

