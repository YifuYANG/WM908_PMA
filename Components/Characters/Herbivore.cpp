#include "Herbivore.h"


Herbivore::Herbivore() {
    HP = rand() % 51;
    MP = 5;
}

Herbivore::Herbivore(int x, int y, int index) : Animal(x, y, index) {
    HP = rand() % 51;
    character = (int) Characters::Herbivore;
    MP = 5;
}

Herbivore::Herbivore(int x, int y) : Animal(x, y) {
    HP = rand() % 51;
    character = (int) Characters::Herbivore;
    MP = 5;
}
