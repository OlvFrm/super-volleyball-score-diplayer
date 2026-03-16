#pragma once

#include "ledDisplayBloc.hpp"



class ServeIndicator : public LedDisplayBloc {

public:

    ServeIndicator();

    void put(bool serve);
};
