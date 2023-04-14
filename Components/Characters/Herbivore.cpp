#include "Herbivore.h"


Herbivore::Herbivore() {
    MP = 5;
}

Herbivore::Herbivore(int x, int y, int index) : Animal(x, y, index) {
    character = (int) Characters::Herbivore;
    MP = 5;
}

Herbivore::Herbivore(int x, int y) : Animal(x, y) {
    character = (int) Characters::Herbivore;
    MP = 5;
}
