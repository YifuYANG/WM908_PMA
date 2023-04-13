//
// Created by Yifu Yang on 13/04/2023.
//

#include "Omnivore.h"

Omnivore::Omnivore() {
    MP = 8;
}

Omnivore::Omnivore(int x, int y,int index) : Animal(x, y, index) {
    MP = 8;
}
