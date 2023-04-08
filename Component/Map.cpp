#include <iostream>
#include "Map.h"
#include <random>

using namespace std;
Map::Map(int x, int y) {
    if(x <= 0 || y <= 0){
        cout << "Error!! X and Y lengths can not be less than zero!!" << endl;
        return;
    }
    this->x=x;
    this->y=y;
    cout<< "Generating ["<< x << " X "<< y<<"] game board"<<endl;
    cout<< "X -> " << x<< endl;
    cout<< "Y -> " << y<< endl;
    this->grid = new int*[y];
    for (int i = 0; i < y; i++) {
        this->grid[i] = new int[x];
        for (int j = 0; j < x; j++) {
            this->grid[i][j] = 0;
        }
    }
}

Map::~Map(){
    delete[] this->grid;
}

void Map::display() {
    for (int i = 0; i < y; i++) {
        // Display the horizontal lines between rows
        cout << string(x * 4, '-') << "-" << endl;

        // Display the contents of each cell in the current row
        for (int j = 0; j < x; j++) {
            cout << "|" << DISPLAY[this->grid[i][j]];
        }
        cout << "| " << i + 1 << endl;
    }
    // Display the final horizontal line at the bottom
    cout << string(x * 4, '-') << "-" << endl;

    // Display the column numbers at the bottom of the board
    for (int i = 0; i < x; i++) {
        cout << "  " << i + 1 << " ";
    }
}

/* generate a number in the range of given bounds:
 * for example: given range -> 1 - 10,
 * it will generate number -> 0 - 9,
 * which corresponding to the array index.
 * no checking is needed
 * */
int Map::random_number_generator(int range) {
    return (rand() % range);
}

//Place a character -> {[1]: T,[2]: H, [3]: C, [4]: O, [5]: R}
void Map::place(int character) {
    int rand_i;
    int rand_j;
    do {
        rand_i=random_number_generator(y);
        rand_j=random_number_generator(x);
    } while (!check_collision(rand_i,rand_j)); {
        grid[rand_i][rand_j] = character;
    }
}

string Map::getXY(int input_i,int input_j) {
    if(!check_boundary(input_i,input_j)){
        return "Error!! Input out of bound!!";
    } else {
        return DISPLAY[grid[input_i-1][input_j-1]];
    }
}

bool Map::check_collision(int input_X,int input_Y) {
    return grid[input_X][input_Y]==0;
}

bool Map::check_boundary(int input_i, int input_j) {
    return input_i <= x && input_j <= y && input_i >= 1 && input_j >= 1;
}
