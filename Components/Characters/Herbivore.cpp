#include "Herbivore.h"


Herbivore::Herbivore() {
    HP = 50;
    MP = 5;
}


Herbivore::Herbivore(int x, int y) : Animal(x, y) {
    HP = 50;
    character = (int) Characters::Herbivore;
    MP = 5;
    FR = 0.03;
            //rand_double_generator();
}
