#include "Vegetation.h"

Vegetation::Vegetation() {
    MP = 0;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}