#include "Vegetation.h"

Vegetation::Vegetation() {
    HP = rand() % 101;
    MP = 0;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}


Vegetation::Vegetation(int x, int y) : Animal(x, y) {
    HP = 100;
    character = (int) Characters::Vegetation;
    MP = 0;
    FR = 0.03;
            //rand_double_generator();
}
