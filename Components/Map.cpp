#include <iostream>
#include "Map.h"
#include <random>
#include <iomanip>
#include "Characters/Vegetation.h"
#include "Characters/Herbivore.h"
#include "Characters/Carnivore.h"
#include "Characters/Omnivore.h"


using namespace std;
/* initial constructor which generates a 2D array with given size,
 * it creates an array with y length,
 * and it creates arrays with in each cell of the outer array.
 * for the designed game board:
 * Y -> vertical size
 * X -> horizontal size
 * */
Map::Map(int x, int y) {
    if(x <= 0 || y <= 0){
        cout << "Error!! X and Y lengths can not be less than zero!!" << endl;
        return;
    }
    this->x=x;
    this->y=y;
    cout<< "==> Generating ["<< y << " X "<< x <<"] game board"<<endl;
    this->board = new int*[y];
    for (int i = 0; i < y; i++) {
        this->board[i] = new int[x];
        for (int j = 0; j < x; j++) {
            this->board[i][j] = 0;
        }
    }
}

Map::~Map(){
    for (int i = 0; i < y; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

void Map::display() {
    for (int i = 0; i < y; i++) {
        // Display the horizontal lines between rows
        cout << string(x * 4, '-') << "-" << endl;

        // Display the contents of each cell in the current row
        for (int j = 0; j < x; j++) {
            cout << "|" << DISPLAY[this->board[i][j]];
        }
        cout << "| " << i + 1 << endl;
    }
    // Display the final horizontal line at the bottom
    cout << string(x * 4, '-') << "-" << endl;

    // Display the column numbers at the bottom of the board
    for (int i = 0; i < x; i++) {
        cout << setw(4) << i + 1;
    }
    //Move to the next line
    cout << endl;
}

/* place a character in a given coordinate,
 * input integer presents the role which is being placed,
 * character number-> {[0]: empty, [1] #, [2]: T, [3]: H, [4]: C, [5]: O, [6]: R}.
 * */
bool Map::placeAt(int input_X, int input_Y, int character) {
    if(!check_boundary(input_X+1,input_Y+1)){
        cout << "Error!! Input: [" << input_X+1<<" X " <<input_Y+1<<"] is out of bound!!" << endl;
        return false;
    } else if(!check_collision(input_X,input_Y)){
        cout << "Error!! Coordinate at: [" << input_X+1<<" X " <<input_Y+1<<"] is not empty!!" << endl;
        return false;
    } else {
        board[input_X][input_Y] = character;
        store_animals_to_container(input_X,input_Y,character);
        if(std::equal(DISPLAY[character].begin(), DISPLAY[character].end()," # ")){
            cout << "==> Placing block [" <<DISPLAY[character]<<"] to coordinate [" << input_X+1<<" X " <<input_Y+1<<"]" << endl;
        } else {
            cout << "==> Placing character [" <<DISPLAY[character]<<"] to coordinate [" << input_X+1<<" X " <<input_Y+1<<"]" << endl;
        }
        return true;
    }
}

string Map::getXY(int input_X,int input_Y) {
    if(!check_boundary(input_X,input_Y)){
        return "Error!! Input out of bound!!";
    } else {
        return DISPLAY[board[input_X-1][input_Y-1]];
    }
}

// helper function for placeAt & rand_place, which checks for collision.
bool Map::check_collision(int input_X,int input_Y) {
    return board[input_X][input_Y]==0;
}

//helper function for placeAt & rand_place, which checks for boundary.
bool Map::check_boundary(int input_X, int input_Y) {
    return input_X <= y && input_Y <= x;
}

int Map::getX() const {
    return x;
}

int Map::getY() const {
    return y;
}

void Map::store_animals_to_container(int input_x, int input_y, int character) {
    Animal* animal;
    switch (character) {
        case 2:
            animal = new Vegetation(input_x, input_y, index);
            break;
        case 3:
            animal = new Herbivore(input_x, input_y, index);
            break;
        case 4:
            animal = new Carnivore(input_x, input_y, index);
            break;
        case 5:
            animal = new Omnivore(input_x, input_y, index);
            break;
        default:
            return;
    }
    list.Insert(animal);
    index++;
}

SinglyLinkedList &Map::getList() {
    return list;
}