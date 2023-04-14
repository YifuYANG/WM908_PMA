#ifndef PMA_CARNIVORE_H
#define PMA_CARNIVORE_H


#include "Animal.h"

class Carnivore : public Animal{
public:
    Carnivore();

    Carnivore(int x,int y, int index);

    Carnivore(int x, int y);
};


#endif //PMA_CARNIVORE_H
