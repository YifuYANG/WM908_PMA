#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
#include "../Enum/Direction.h"

using namespace std;
class Animal {
protected:
    int MP;
    int X, Y;
    int character;
    int HP;
private:

    double rand_double_generator();

    double probability_generator_for_not_moving();

    double probability_generator_for_moving();

    Direction rand_direction_generator();

public:

    Animal();

    int getMp();

    void move();


    int getX();

    int getY();


    int getCharacter();

    Animal(int x, int y);

    void setX(int x);

    void setY(int y);

    int getHp();

    void setHp(int hp);
};


#endif //PMA_ANIMAL_H
