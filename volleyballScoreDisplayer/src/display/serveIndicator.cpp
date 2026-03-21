#include "display/serveIndicator.hpp"


ServeIndicator::ServeIndicator():
    LedDisplayBloc(1) {}

void ServeIndicator::put(CRGB color) {
    if (!isReady()) {
        Serial.println("Bloc error...");
        return;
    }

    ledStrip_->getLeds()[ledOffset_] = color;
}

