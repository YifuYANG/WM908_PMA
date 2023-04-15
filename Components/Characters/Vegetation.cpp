#include "Vegetation.h"

Vegetation::Vegetation() {
    HP = rand() % 101;
    MP = 0;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}

Vegetation::Vegetation(int x, int y, int index) : Animal(x, y,index) {
    HP = rand() % 101;
    character = (int) Characters::Vegetation;
    MP = 0;
}

Vegetation::Vegetation(int x, int y) : Animal(x, y) {
    HP = rand() % 101;
    character = (int) Characters::Vegetation;
    MP = 0;
}
