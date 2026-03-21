#pragma once

#include "ledDisplayBloc.hpp"


/*
    Sets can be either in
    - Least Significant Set first (LSS)
    - Most Significant Set first (MSS) (reversed)
 */


class SetCounter : public LedDisplayBloc {

private:
    bool reversed_;

public:

    SetCounter();

    void setReversed(bool reversed);
    void put(unsigned int setNumber, CRGB color);
};
