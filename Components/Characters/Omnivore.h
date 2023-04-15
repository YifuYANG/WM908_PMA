#ifndef PMA_OMNIVORE_H
#define PMA_OMNIVORE_H
#include "../Enum/Characters.h"

#include "Animal.h"

class Omnivore : public Animal {
public:
    Omnivore();

    Omnivore(int x, int y, int index);

    Omnivore(int x, int y);
};


#endif //PMA_OMNIVORE_H