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
}

double Animal::probability_generator_for_not_moving() {
    return ((double)MP-4)/(double)MP;
}

double Animal::probability_generator_for_moving() {
    return (1-probability_generator_for_not_moving())/4;
}


int Animal::getMp(){
    return MP;
}


int Animal::getX() {
    return X;
}

int Animal::getY() {
    return Y;
}


void Animal::move() {
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


int Animal::getCharacter() {
    return character;
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

int Animal::getHp() {
    return HP;
}

void Animal::setHp(int hp) {
    HP = hp;
}

double Animal::getFr() {
    return FR;
}
