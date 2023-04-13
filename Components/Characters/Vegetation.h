#ifndef PMA_VEGETATION_H
#define PMA_VEGETATION_H
#include "Animal.h"

class Vegetation : public Animal {
public:
    Vegetation();
    static Direction move();
};


#endif //PMA_VEGETATION_H
