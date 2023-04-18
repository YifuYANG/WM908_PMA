#include "Herbivore.h"


Herbivore::Herbivore() {
    HP = settings.H_HP;
    character = (int) Characters::Herbivore;
    MP = settings.H_MP;
    FR = settings.FR_H;
}


Herbivore::Herbivore(int x, int y) : Animal(x, y) {
    HP = settings.H_HP;
    character = (int) Characters::Herbivore;
    MP = settings.H_MP;
    FR = settings.FR_H;
}
