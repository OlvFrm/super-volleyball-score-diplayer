#include "display/ledDisplayBloc.hpp"


#define DEFAULT_COLOR CRGB::Red


LedDisplayBloc::LedDisplayBloc(int size):
            size_(size), ledOffset_(0), ledStrip_(nullptr), attached_(false), color_(DEFAULT_COLOR) {}


bool LedDisplayBloc::isReady() {
    return attached_ && (ledStrip_->getSize() != 0);
}

 
void LedDisplayBloc::addTo(LedStrip& ledStrip) {
    if (attached_) {
        Serial.println("Bloc already attached...");
        return;
    }
    ledStrip_ = &ledStrip;
    ledOffset_ = ledStrip.getSize();
    ledStrip.addBloc(size_);
    attached_ = true;
}


void LedDisplayBloc::setColor(CRGB color) {
    color_ = color;
}

