#include "Omnivore.h"


Omnivore::Omnivore() {
    HP = rand() % 51;
    MP = 8;
}

Omnivore::Omnivore(int x, int y) : Animal(x, y) {
    HP = rand() % 51;
    character = (int) Characters::Omnivore;
    MP = 8;
    FR = rand_double_generator();
}