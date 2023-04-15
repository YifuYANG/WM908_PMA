#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
#include "../Enum/Direction.h"

using namespace std;
class Animal {
protected:
    int MP;
    int X, Y;
    int save_x=-1, save_y=-1;
    int index;
    int character;
private:

    bool whether_this_animal_has_moved_or_not;

    double rand_double_generator();

    double probability_generator_for_not_moving();

    double probability_generator_for_moving();

    Direction rand_direction_generator();

public:
    bool isWhetherThisAnimalHasMovedOrNot();

    Animal();

    int getMp();

    void move();

    Animal(int x, int y, int index);

    int getX();

    int getY();

    int getIndex();

    int getCharacter();

    void setWhetherThisAnimalHasMovedOrNot(bool whetherThisAnimalHasMovedOrNot);

    void setIndex(int index);

    Animal(int x, int y);

    void setX(int x);

    void setY(int y);

    int getSaveX();

    void setSaveX(int saveX);

    int getSaveY();

    void setSaveY(int saveY);

    bool check_for_same_position();
};


#endif //PMA_ANIMAL_H
