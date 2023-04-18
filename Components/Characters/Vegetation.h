#ifndef PMA_VEGETATION_H
#define PMA_VEGETATION_H
#include "Animal.h"
#include "../Enum/Characters.h"
#include "../../Settings/Settings.h"
class Vegetation : public Animal {
private:
    Settings settings;
public:
    Vegetation();

    Direction move();

    Vegetation(int x, int y);
};


#endif //PMA_VEGETATION_H
