#pragma once

#include "button.hpp"


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

  void S1();
  void L1();
  void R1();

  void S2();
  void L2();
  void R2();

  void SD();
  void LD();


public:

  ButtonHandler();

  void init();

  void checkUserInput();
};