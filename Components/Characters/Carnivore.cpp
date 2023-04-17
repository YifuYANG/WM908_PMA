#include "Carnivore.h"


Carnivore::Carnivore() {
    HP = rand() % 51;
    MP = 5;
}


Carnivore::Carnivore(int x, int y) : Animal(x, y) {
    HP = rand() % 51;
    character = (int) Characters::Carnivore;
    MP = 5;
}
