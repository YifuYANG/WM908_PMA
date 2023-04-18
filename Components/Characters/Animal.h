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
    double FR;
private:

    double probability_generator_for_not_moving();

    double probability_generator_for_moving();

    Direction rand_direction_generator();

public:

    double rand_double_generator();

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

    double getFr();
};


#endif //PMA_ANIMAL_H
