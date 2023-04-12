#include "Animal.h"
#include "iostream"
using namespace std;
Animal::Animal(bool isMoved) {
    this->whether_this_animal_has_moved_or_not=isMoved;
}

bool Animal::check_whether_this_animal_has_moved_or_not() {
    return whether_this_animal_has_moved_or_not;
}

void Animal::setIsMoved(bool ismoved) {
    this->whether_this_animal_has_moved_or_not = ismoved;
}

void Animal::move() {

}
