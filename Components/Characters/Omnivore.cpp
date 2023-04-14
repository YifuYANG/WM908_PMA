#include "Omnivore.h"


Omnivore::Omnivore() {
    MP = 8;
}

Omnivore::Omnivore(int x, int y,int index) : Animal(x, y, index) {
    character = (int) Characters::Omnivore;
    MP = 8;
}

Omnivore::Omnivore(int x, int y) : Animal(x, y) {
    character = (int) Characters::Omnivore;
    MP = 8;
}