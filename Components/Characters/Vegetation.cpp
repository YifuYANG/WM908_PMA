#include "Vegetation.h"

Vegetation::Vegetation() {
    HP = settings.T_HP;
    character = (int) Characters::Vegetation;
    MP = settings.T_MP;
    FR = settings.FR_T;
}

Direction Vegetation::move() {
    return Direction::Not_Moving;
}


Vegetation::Vegetation(int x, int y) : Animal(x, y) {
    HP = settings.T_HP;
    character = (int) Characters::Vegetation;
    MP = settings.T_MP;
    FR = settings.FR_T;
}
