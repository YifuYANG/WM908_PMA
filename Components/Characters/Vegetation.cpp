#include "Vegetation.h"

Vegetation::Vegetation() {
    MP = 0;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}

Vegetation::Vegetation(int x, int y) : Animal(x, y) {
    MP = 0;
}
