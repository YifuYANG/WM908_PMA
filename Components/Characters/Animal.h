#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
using namespace std;
class Animal {
private:
    int X,Y;
    bool whether_this_animal_has_moved_or_not;

    int movement_parameter_generator();

    bool check_boundary(int X, int Y,int boundary_X, int boundary_Y);

public:
    Animal(int X, int Y);

    Animal();

    void move();
};


#endif //PMA_ANIMAL_H
