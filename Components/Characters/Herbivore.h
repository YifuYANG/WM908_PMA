#ifndef PMA_HERBIVORE_H
#define PMA_HERBIVORE_H
#include "Animal.h"
#include "../Enum/Characters.h"
#include "../../Settings/Settings.h"
class Herbivore : public Animal{
private:
    Settings settings;
public:
    Herbivore();

    Herbivore(int x, int y);
};


#endif //PMA_HERBIVORE_H
