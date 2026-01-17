#pragma once

#include "button.hpp"

#define BUTTON_A_PIN  2
#define BUTTON_B_PIN  3


class ButtonHandler {
private:

  static constexpr unsigned long REPEAT_RATE = 200;
  static constexpr unsigned long LONG_PRESS = 1200;

  enum State {
    IDLE,
    B1_PRESSED,
    B1_HELD,
    B2_PRESSED,
    B2_HELD,
    BOTH,
    WAIT
  };

  Button b1_;
  Button b2_;

  State currentState_ = State::IDLE;

  unsigned long doubleStart_ = 0;
  unsigned long repeatLastTrigger_ = 0;

  void S1() { Serial.println("S1: Button 1 short"); }
  void L1() { Serial.println("L1: Button 1 long"); }
  void R1() { Serial.println("R1: Button 1 repeat"); }

  void S2() { Serial.println("S2: Button 2 short"); }
  void L2() { Serial.println("L2: Button 2 long"); }
  void R2() { Serial.println("R2: Button 2 repeat"); }

  void SD() { Serial.println("SD: Double short"); }
  void LD() { Serial.println("LD: Double long"); }


public:

  ButtonHandler()
    : b1_(BUTTON_A_PIN), b2_(BUTTON_B_PIN) {}

  void init() {
    // Init button GPIO
    pinMode(BUTTON_A_PIN, INPUT_PULLUP);
    pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  }

  void checkUserInput() {
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
          S1();
          currentState_ = State::IDLE;
        } else if (b2_.isPressed()) {
          doubleStart_ = now;
          currentState_ = State::BOTH;
        } else if ((now - b1_.pressTime()) > LONG_PRESS) {
          L1();
          repeatLastTrigger_ = now;
          currentState_ = State::B1_HELD;
        }
        break;

      case State::B1_HELD:
        if (!b1_.isPressed()) {
          currentState_ = State::IDLE;
        } else if ((now - repeatLastTrigger_) > REPEAT_RATE) {
          R1();
          repeatLastTrigger_ = now;
        }
        break;

      /* ---------- Button 2 ---------- */
      case State::B2_PRESSED:
        if (!b2_.isPressed()) {
          S2();
          currentState_ = State::IDLE;
        } else if (b1_.isPressed()) {
          doubleStart_ = now;
          currentState_ = State::BOTH;
        } else if ((now - b2_.pressTime()) > LONG_PRESS) {
          L2();
          repeatLastTrigger_ = now;
          currentState_ = State::B2_HELD;
        }
        break;

      case State::B2_HELD:
        if (!b2_.isPressed()) {
          currentState_ = State::IDLE;
        } else if ((now - repeatLastTrigger_) > REPEAT_RATE) {
          R2();
          repeatLastTrigger_ = now;
        }
        break;

      /* ---------- Both buttons ---------- */
      case State::BOTH:
        if (!b1_.isPressed() || !b2_.isPressed()) {
          SD();
          currentState_ = State::WAIT;
        } else if ((now - doubleStart_) > LONG_PRESS) {
          LD();
          currentState_ = State::WAIT;
        }
        break;

      case State::WAIT:
        if (!b1_.isPressed() && !b2_.isPressed()) {
          currentState_ = State::IDLE;
        }
        break;


      default:
        Serial.println("What have you done?");
        break;
    }
  }
};