//
// Created by Yifu Yang on 13/04/2023.
//

#include "Carnivore.h"

Carnivore::Carnivore() {
    MP = 5;
}

Carnivore::Carnivore(int x, int y) : Animal(x, y) {
    MP = 5;
    this->X=x;
    this->Y=y;
}
