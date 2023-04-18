#include "Omnivore.h"


Omnivore::Omnivore() {
    HP = settings.O_HP;
    character = (int) Characters::Omnivore;
    MP = settings.O_MP;
    FR = settings.FR_O;
}

Omnivore::Omnivore(int x, int y) : Animal(x, y) {
    HP = settings.O_HP;
    character = (int) Characters::Omnivore;
    MP = settings.O_MP;
    FR = settings.FR_O;
}