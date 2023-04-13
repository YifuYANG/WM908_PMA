#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
#include "../Enum/Direction.h"

using namespace std;
class Animal {
protected:
    int MP;

private:

    bool whether_this_animal_has_moved_or_not;

    double rand_double_generator();

    double probability_generator_for_not_moving();

    double probability_generator_for_moving();

public:
    bool isWhetherThisAnimalHasMovedOrNot();

    Animal();

    int getMp();

    Direction move();
};


#endif //PMA_ANIMAL_H
