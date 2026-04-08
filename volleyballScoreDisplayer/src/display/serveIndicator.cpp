#include "display/serveIndicator.hpp"
#include "tools/log.hpp"

#define SERVE_LED_NUMBER    1

ServeIndicator::ServeIndicator():
    LedDisplayBloc(SERVE_LED_NUMBER) {}

void ServeIndicator::put(bool show) {
    if (!isReady()) {
        LOG_ERROR("Bloc error...");
        return;
    }

    for (int i = 0; i < SERVE_LED_NUMBER; i++) {
        ledStrip_->getLeds()[ledOffset_ + i] = show ? color_ : CRGB::Black;
    }
}

