#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
#include "../Enum/Direction.h"

using namespace std;
class Animal {
protected:
    int MP;
    int X, Y;
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

    Animal(int x, int y);

    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int y);
};


#endif //PMA_ANIMAL_H
