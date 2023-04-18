#ifndef PMA_OMNIVORE_H
#define PMA_OMNIVORE_H
#include "../Enum/Characters.h"
#include "../../Settings/Settings.h"
#include "Animal.h"

class Omnivore : public Animal {
private:
    Settings settings;
public:
    Omnivore();

    Omnivore(int x, int y);
};


#endif //PMA_OMNIVORE_H
