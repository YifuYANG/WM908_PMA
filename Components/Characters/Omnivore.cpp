//
// Created by Yifu Yang on 13/04/2023.
//

#include "Omnivore.h"
#include "../Enum/Characters.h"

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