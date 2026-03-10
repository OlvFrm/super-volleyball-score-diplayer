#include "display/serveIndicator.hpp"


ServeIndicator::ServeIndicator():
    LedDisplayBloc(1) {}

void ServeIndicator::put(bool serve) {
    if (!isReady()) {
        Serial.println("Bloc error...");
        return;
    }

    ledStrip_->getLeds()[ledOffset_] = serve ? color_ : CRGB::Black;
}

