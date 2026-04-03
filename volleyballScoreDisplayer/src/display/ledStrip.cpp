#include "display/ledStrip.hpp"


#define LED_PIN 5


LedStrip::LedStrip(): numLeds_(0), leds_(nullptr) {}

LedStrip::~LedStrip() {
    if (leds_ != nullptr) {
        delete[] leds_;
        leds_ = nullptr;
    }
}

void LedStrip::addBloc(int blocSize) {
    numLeds_ += blocSize;
}

void LedStrip::init() {
    // Init RGB LEDs strip
    if (leds_ != nullptr) {
        Serial.println("Must init LedStrip only once...");
        return;
    }
    if (numLeds_ == 0) {
        Serial.println("Need at least one bloc...");
        return;
    }

    leds_ = new CRGB[numLeds_];
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds_, numLeds_);
    FastLED.setBrightness(10);
}

int LedStrip::getSize() {
    return numLeds_;
}

CRGB* LedStrip::getLeds() {
    return leds_;
}

void LedStrip::show() {
    FastLED.show();
}
