#ifndef PMA_CARNIVORE_H
#define PMA_CARNIVORE_H
#include "../Enum/Characters.h"
#include <random>
using namespace std;

#include "Animal.h"

class Carnivore : public Animal{
public:
    Carnivore();


    Carnivore(int x, int y);
};


#endif //PMA_CARNIVORE_H
