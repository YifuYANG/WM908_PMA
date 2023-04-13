#include "Animal.h"
#include <random>
using namespace std;

Direction Animal::move() {
    double distribution = rand_double_generator();
    if(distribution >=0 && distribution <= probability_generator_for_moving()){//0 -0.16
        return Direction::North;
    } else if (distribution >= probability_generator_for_moving() && distribution <= probability_generator_for_moving()*2){
        return Direction::South;
    } else if (distribution >= probability_generator_for_moving()*2 && distribution <= probability_generator_for_moving()*3){
        return Direction::West;
    } else if (distribution >= probability_generator_for_moving()*3 && distribution <= probability_generator_for_moving()*4){
        return Direction::East;
    } else {
        return Direction::Not_Moving;
    }
}

double Animal::rand_double_generator() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0, 1);
    return dis(gen);
}

Animal::Animal() {
    whether_this_animal_has_moved_or_not=false;
}

double Animal::probability_generator_for_not_moving() {
    return ((double)MP-4)/(double)MP;
}

double Animal::probability_generator_for_moving() {
    return (1-probability_generator_for_not_moving())/4;
}

bool Animal::isWhetherThisAnimalHasMovedOrNot(){
    return whether_this_animal_has_moved_or_not;
}

int Animal::getMp(){
    return MP;
}
