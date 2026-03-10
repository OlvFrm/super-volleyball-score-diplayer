#pragma once

#include "ledDisplayBloc.hpp"


/*
Sets can be either in
 - Most Significant Set first (MSS)
 - Least Significant Set first (LSS)
 */


class SetCounter : public LedDisplayBloc {

private:
    bool reversed_;

public:

    SetCounter(bool reversed);

    void put(int setNumber);
};
