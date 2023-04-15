#include "Animal.h"
#include <random>
using namespace std;

Direction Animal::rand_direction_generator() {
    double distribution = rand_double_generator();
    if(distribution >=0 && distribution <= probability_generator_for_moving()){
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

Animal::Animal(int x, int y, int index) {
    this->X = x;
    this->Y = y;
    this->index = index;
}

int Animal::getX() {
    return X;
}

int Animal::getY() {
    return Y;
}


void Animal::move() {
    save_x = X;
    save_y = Y;
    Direction drection=rand_direction_generator();
    if((int)drection == 0){
        X = X - 1;
    } else if ((int)drection == 1){
        X = X + 1;
    } else if ((int)drection == 2){
        Y = Y + 1;
    } else if ((int)drection == 3){
        Y = Y - 1;
    }
}

int Animal::getIndex() {
    return index;
}

int Animal::getCharacter() {
    return character;
}

void Animal::setWhetherThisAnimalHasMovedOrNot(bool whetherThisAnimalHasMovedOrNot) {
    whether_this_animal_has_moved_or_not = whetherThisAnimalHasMovedOrNot;
}

void Animal::setIndex(int index) {
    Animal::index = index;
}

Animal::Animal(int x, int y){
    this->X = x;
    this->Y = y;
}

void Animal::setX(int x) {
    X = x;
}

void Animal::setY(int y) {
    Y = y;
}

int Animal::getSaveX() {
    return save_x;
}

void Animal::setSaveX(int saveX) {
    save_x = saveX;
}

int Animal::getSaveY() {
    return save_y;
}

void Animal::setSaveY(int saveY) {
    save_y = saveY;
}

bool Animal::check_for_same_position() {
    return save_y == Y && save_x == X;
}