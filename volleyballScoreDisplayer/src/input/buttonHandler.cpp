#include "input/buttonHandler.hpp"
#include <Arduino.h>
#include "tools/log.hpp"


#define BUTTON_LEFT_PIN  2
#define BUTTON_WRITE_PIN  3



void ButtonHandler::S1() { LOG_DEBUG("S1: Button 1 short"); }
void ButtonHandler::L1() { LOG_DEBUG("L1: Button 1 long"); }
void ButtonHandler::R1() { LOG_DEBUG("R1: Button 1 repeat"); }

void ButtonHandler::S2() { LOG_DEBUG("S2: Button 2 short"); }
void ButtonHandler::L2() { LOG_DEBUG("L2: Button 2 long"); }
void ButtonHandler::R2() { LOG_DEBUG("R2: Button 2 repeat"); }

void ButtonHandler::SD() { LOG_DEBUG("SD: Double short"); }
void ButtonHandler::LD() { LOG_DEBUG("LD: Double long"); }


ButtonHandler::ButtonHandler(): b1_(BUTTON_LEFT_PIN), b2_(BUTTON_WRITE_PIN) {}

void ButtonHandler::init() {
    // Init button GPIO
    pinMode(BUTTON_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_WRITE_PIN, INPUT_PULLUP);
}

Event ButtonHandler::checkUserInput() {
    unsigned long now = millis();

    b1_.update(now);
    b2_.update(now);

    switch (currentState_) {

        case State::IDLE:
        if (b1_.isPressed() && b2_.isPressed()) {
            doubleStart_ = now;
            currentState_ = State::BOTH;
        } else if (b1_.isPressed()) {
            currentState_ = State::B1_PRESSED;
        } else if (b2_.isPressed()) {
            currentState_ = State::B2_PRESSED;
        }
        break;

        /* ---------- Button 1 ---------- */
        case State::B1_PRESSED:
        if (!b1_.isPressed()) {
            currentState_ = State::IDLE;
            return Event::LEFT_SHORT;
        } else if (b2_.isPressed()) {
            doubleStart_ = now;
            currentState_ = State::BOTH;
        } else if ((now - b1_.pressTime()) > LONG_PRESS) {
            repeatLastTrigger_ = now;
            currentState_ = State::B1_HELD;
            return Event::LEFT_LONG;
        }
        break;

        case State::B1_HELD:
        if (!b1_.isPressed()) {
            currentState_ = State::IDLE;
        } else if ((now - repeatLastTrigger_) > REPEAT_RATE) {
            repeatLastTrigger_ = now;
            return Event::LEFT_REPEAT;
        }
        break;

        /* ---------- Button 2 ---------- */
        case State::B2_PRESSED:
        if (!b2_.isPressed()) {
            currentState_ = State::IDLE;
            return Event::RIGHT_SHORT;
        } else if (b1_.isPressed()) {
            doubleStart_ = now;
            currentState_ = State::BOTH;
        } else if ((now - b2_.pressTime()) > LONG_PRESS) {
            repeatLastTrigger_ = now;
            currentState_ = State::B2_HELD;
            return Event::RIGHT_LONG;
        }
        break;

        case State::B2_HELD:
        if (!b2_.isPressed()) {
            currentState_ = State::IDLE;
        } else if ((now - repeatLastTrigger_) > REPEAT_RATE) {
            repeatLastTrigger_ = now;
            return Event::RIGHT_REPEAT;
        }
        break;

        /* ---------- Both buttons ---------- */
        case State::BOTH:
        if (!b1_.isPressed() || !b2_.isPressed()) {
            currentState_ = State::WAIT;
            return Event::DOUBLE_SHORT;
        } else if ((now - doubleStart_) > LONG_PRESS) {
            currentState_ = State::WAIT;
            return Event::DOUBLE_LONG;
        }
        break;

        case State::WAIT:
        if (!b1_.isPressed() && !b2_.isPressed()) {
            currentState_ = State::IDLE;
        }
        break;


        default:
        LOG_ERROR("What have you done?");
        break;
    }

    return Event::NONE;
}
