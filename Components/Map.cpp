#include <iostream>
#include "Map.h"
#include <random>
#include <iomanip>

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
    //delete[] this->board;
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

/* place a character randomly,
 * the do-while loop will continue generating random coordinates,
 * until there is no collision at the generated coordinate,
 * input integer presents the role which is being placed,
 * character number-> {[0]: empty, [1] #, [2]: T, [3]: H, [4]: C, [5]: O, [6]: R}.
 * */
void Map::rand_place(int character) {
    int rand_i;
    int rand_j;
    do {
        rand_i=random_number_generator(y);
        rand_j=random_number_generator(x);
    } while (!check_collision(rand_i, rand_j));
    board[rand_i][rand_j] = character;
    if(std::equal(DISPLAY[character].begin(), DISPLAY[character].end()," # ")){
        cout << "==> Placing block [" <<DISPLAY[character]<<"] to coordinate [" << rand_i+1<<" X " <<rand_j+1<<"]" << endl;
    } else {
        cout << "==> Placing character [" <<DISPLAY[character]<<"] to coordinate [" << rand_i+1<<" X " <<rand_j+1<<"]" << endl;
    }
}

/* place a character in a given coordinate,
 * input integer presents the role which is being placed,
 * character number-> {[0]: empty, [1] #, [2]: T, [3]: H, [4]: C, [5]: O, [6]: R}.
 * */
void Map::placeAt(int input_X, int input_Y, int character) {
    if(!check_boundary(input_X,input_Y)){
        cout << "Error!! Input: [" << input_X<<" X " <<input_Y<<"] is out of bound!!" << endl;
    } else if(!check_collision(input_X-1,input_Y-1)){
        cout << "Error!! Coordinate at: [" << input_X<<" X " <<input_Y<<"] is not empty!!" << endl;
    } else {
        board[input_X-1][input_Y-1] = character;
        if(std::equal(DISPLAY[character].begin(), DISPLAY[character].end()," # ")){
            cout << "==> Placing block [" <<DISPLAY[character]<<"] to coordinate [" << input_X<<" X " <<input_Y<<"]" << endl;
        } else {
            cout << "==> Placing character [" <<DISPLAY[character]<<"] to coordinate [" << input_X<<" X " <<input_Y<<"]" << endl;
        }
    }
}

string Map::getXY(int input_X,int input_Y) {
    if(!check_boundary(input_X,input_Y)){
        return "Error!! Input out of bound!!";
    } else {
        return DISPLAY[board[input_X-1][input_Y-1]];
    }
}

/* helper function for rand_place:
 * generate a random number in the range of given bounds,
 * for example: given range -> 1 - 10,
 * it will generate number -> 0 - 9,
 * which corresponds to the array index.
 * no checking is needed.
 * */
int Map::random_number_generator(int range) {
    return (rand() % range);
}

// helper function for placeAt & rand_place, which checks for collision.
bool Map::check_collision(int input_X,int input_Y) {
    return board[input_X][input_Y]==0;
}

//helper function for placeAt & rand_place, which checks for boundary.
bool Map::check_boundary(int input_X, int input_Y) {
    return input_X <= y && input_Y <= x && input_X >= 1 && input_Y >= 1;
}

int Map::getX() const {
    return x;
}

int Map::getY() const {
    return y;
}
