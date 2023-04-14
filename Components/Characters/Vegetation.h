#ifndef PMA_VEGETATION_H
#define PMA_VEGETATION_H
#include "Animal.h"
#include "../Enum/Characters.h"

class Vegetation : public Animal {
public:
    Vegetation();
    static Direction move();

    Vegetation(int x, int y, int index);

    Vegetation(int x, int y);
};


#endif //PMA_VEGETATION_H
