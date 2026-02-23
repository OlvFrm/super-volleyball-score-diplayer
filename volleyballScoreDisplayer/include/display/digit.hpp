#pragma once

#include "ledDisplayBloc.hpp"


/* Assuming segments are arranged like:
  --2--
 |     |
 1     3
 |     |
  --4--
 |     |
 5     7
 |     |
  --6--
 */


class Digit : public LedDisplayBloc {

public:
  Digit();

  void put(int digit);
};
