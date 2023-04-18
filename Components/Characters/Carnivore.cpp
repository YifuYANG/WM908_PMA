#include "Carnivore.h"


Carnivore::Carnivore() {
    HP = 50;
    MP = 5;
}


Carnivore::Carnivore(int x, int y) : Animal(x, y) {
    HP = 50;
    character = (int) Characters::Carnivore;
    MP = 5;
    FR = 0.03;
            //rand_double_generator();
}
