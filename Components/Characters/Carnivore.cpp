#include "Carnivore.h"


Carnivore::Carnivore() {
    HP = setting.C_HP;
    character = (int) Characters::Carnivore;
    MP = setting.C_MP;
    FR = setting.FR_C;
}


Carnivore::Carnivore(int x, int y) : Animal(x, y) {
    HP = setting.C_HP;
    character = (int) Characters::Carnivore;
    MP = setting.C_MP;
    FR = setting.FR_C;
}
