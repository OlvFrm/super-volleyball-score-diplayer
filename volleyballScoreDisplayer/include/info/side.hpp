#pragma once

enum Side {
    LEFT, RIGHT
};

inline void switchSide(Side& side) {
    side = side == LEFT ? RIGHT : LEFT;
}