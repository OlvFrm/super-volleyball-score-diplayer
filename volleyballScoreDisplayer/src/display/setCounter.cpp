#include "display/setCounter.hpp"
#include "tools/log.hpp"

#define NUMBER_OF_SET   3

SetCounter::SetCounter():
    LedDisplayBloc(NUMBER_OF_SET), reversed_(false) {}

void SetCounter::setReversed(bool reversed) { reversed_ = reversed; }

void SetCounter::put(unsigned int setNumber) {
    if (!isReady()) {
        LOG_ERROR("Bloc error...");
        return;
    }
    if (setNumber > NUMBER_OF_SET) {
        LOG_ERROR("Incorrect set number...");
        return;
    }

    // Looping for all LEDs
    int currentIndex = ledOffset_;
    unsigned int currentSetLed;
    for (unsigned int set = 1; set <= NUMBER_OF_SET; set++) {

        currentSetLed = reversed_ ? NUMBER_OF_SET - set +1 : set;
        ledStrip_->getLeds()[currentIndex] = currentSetLed <= setNumber ? color_ : CRGB::Black;
        
        currentIndex++;
    }
}

