#include "display/setCounter.hpp"

#define NUMBER_OF_SET   3

SetCounter::SetCounter(bool reversed):
    LedDisplayBloc(NUMBER_OF_SET), reversed_(reversed) {}

void SetCounter::put(int setNumber) {
    if (!isReady()) {
        Serial.println("Bloc error...");
        return;
    }
    if (setNumber < 0 || setNumber > NUMBER_OF_SET) {
        Serial.println("Incorrect set number...");
        return;
    }

    // Looping for all LEDs
    int currentIndex = ledOffset_;
    int currentSetLed;
    for (int set = 1; set <= NUMBER_OF_SET; set++) {

        currentSetLed = reversed_ ? NUMBER_OF_SET - set +1 : set;
        ledStrip_->getLeds()[currentIndex] = currentSetLed <= setNumber ? color_ : CRGB::Black;
        
        currentIndex++;
    }
}

