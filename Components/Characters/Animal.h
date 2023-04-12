#ifndef PMA_ANIMAL_H
#define PMA_ANIMAL_H
#include "iostream"
using namespace std;
class Animal {
private:
    enum MP {
        East = 0,
        West = 1,
        South = 2,
        North = 3
    };

    bool whether_this_animal_has_moved_or_not=false;
    int MP;
public:
    Animal(bool isMoved);

    bool check_whether_this_animal_has_moved_or_not();

    void setIsMoved(bool isMoved);

    void move();
};


#endif //PMA_ANIMAL_H
