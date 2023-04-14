//
// Created by Yifu Yang on 13/04/2023.
//

#include "Carnivore.h"
#include "../Enum/Characters.h"

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
