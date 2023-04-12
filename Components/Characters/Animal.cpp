#include "Animal.h"
#include "iostream"
using namespace std;
void Animal::move() {
    int MP = movement_parameter_generator();
    if(MP == 0){
        Y = Y + 1;
    } else if (MP == 1){
        Y = Y - 1;
    } else if (MP == 2){
        X = X + 1;
    } else if (MP == 3){
        X =X - 1;
    }
}

Animal::Animal(int X, int Y) {
    this->X = X;
    this->Y = Y;
}

int Animal::movement_parameter_generator() {
    return rand() % 5;
}

bool Animal::check_boundary(int x, int y, int boundary_X, int boundary_Y) {
    return X+1 <= boundary_Y && Y+1 <= boundary_X;
}

Animal::Animal() {
    whether_this_animal_has_moved_or_not=false;
}
