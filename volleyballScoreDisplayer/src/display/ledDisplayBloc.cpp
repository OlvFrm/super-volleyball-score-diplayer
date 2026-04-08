#include "display/ledDisplayBloc.hpp"
#include "tools/log.hpp"


LedDisplayBloc::LedDisplayBloc(int size):
            size_(size), ledOffset_(0), ledStrip_(nullptr), attached_(false), color_(CRGB::Black) {}


bool LedDisplayBloc::isReady() {
    return attached_ && (ledStrip_->getSize() != 0);
}

 
void LedDisplayBloc::addTo(LedStrip& ledStrip) {
    if (attached_) {
        LOG_ERROR("Bloc already attached...");
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

