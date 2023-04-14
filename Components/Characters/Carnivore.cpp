#include "Carnivore.h"


Carnivore::Carnivore() {
    MP = 5;
}

Carnivore::Carnivore(int x, int y,int index) : Animal(x, y,index) {
    character = (int) Characters::Carnivore;
    MP = 5;
}

Carnivore::Carnivore(int x, int y) : Animal(x, y) {
    character = (int) Characters::Carnivore;
    MP = 5;
}
