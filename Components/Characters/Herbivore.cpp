//
// Created by Yifu Yang on 13/04/2023.
//

#include "Herbivore.h"

Herbivore::Herbivore() {
    MP = 5;
}

Herbivore::Herbivore(int x, int y, int index) : Animal(x, y, index) {
    MP = 5;
}
