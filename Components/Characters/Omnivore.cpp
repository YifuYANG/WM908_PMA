#include "Omnivore.h"


Omnivore::Omnivore() {
    HP = 50;
    MP = 8;
}

Omnivore::Omnivore(int x, int y) : Animal(x, y) {
    HP = 50;
    character = (int) Characters::Omnivore;
    MP = 8;
    FR = 0.03;
            //rand_double_generator();
}