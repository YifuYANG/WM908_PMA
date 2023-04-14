#include "Vegetation.h"

Vegetation::Vegetation() {
    MP = 0;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}

Vegetation::Vegetation(int x, int y, int index) : Animal(x, y,index) {
    character = (int) Characters::Vegetation;
    MP = 0;
}

Vegetation::Vegetation(int x, int y) : Animal(x, y) {
    character = (int) Characters::Vegetation;
    MP = 0;
}
