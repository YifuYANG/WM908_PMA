#include "Map.h"

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
    place_blocks();
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
            Animal *curr;
            if(list.getByXY(i,j) != nullptr){
                curr = list.getByXY(i,j)->getData();
                if(DISPLAY[this->board[i][j]]==" T "){
                    if(curr->getHp()<33 && curr->getHp()>=0){
                        cout << "|" << " ‘ ";
                    } else if (curr->getHp()<66 && curr->getHp()>=33){
                        cout << "|" << " t ";
                    } else {
                        cout << "|" << DISPLAY[this->board[i][j]];
                    }
                } else if(DISPLAY[this->board[i][j]]==" H "){
                    if(curr->getHp()<25){
                        cout << "|" << " h ";
                    } else {
                        cout << "|" << DISPLAY[this->board[i][j]];
                    }
                } else if(DISPLAY[this->board[i][j]]==" C "){
                    if(curr->getHp()<25){
                        cout << "|" << " c ";
                    } else {
                        cout << "|" << DISPLAY[this->board[i][j]];
                    }
                } else if(DISPLAY[this->board[i][j]]==" O "){
                    if(curr->getHp()<25){
                        cout << "|" << " o ";
                    } else {
                        cout << "|" << DISPLAY[this->board[i][j]];
                    }
                }
            } else {
                cout << "|" << DISPLAY[this->board[i][j]];
            }
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
bool Map::placeAt(Animal animal) {
    int X = animal.getX();
    int Y = animal.getY();
    int character = animal.getCharacter();
    if (!check_boundary(X, Y) || check_collision(X, Y)) {
        return false;
    }
    board[X][Y] = character;
    return true;
}


bool Map::getXY(int input_X, int input_Y) {
    return check_boundary(input_X, input_Y) && board[input_X][input_Y] != 0 && board[input_X][input_Y] != 1;
}

// helper function for placeAt & rand_place, which checks for collision.
bool Map::check_collision(int input_X,int input_Y) {
    return board[input_X][input_Y] != 0;
}

//helper function for placeAt & rand_place, which checks for boundary.
bool Map::check_boundary(int input_X, int input_Y) {
    return input_X >= 0 && input_Y >= 0 && input_X <= y-1 && input_Y <= x-1;
}

int Map::getX() const {
    return x;
}

int Map::getY() const {
    return y;
}

void Map::store_animals_to_container(int character, int in_x, int in_y) {
    switch (character) {
        case 2:
            list.Insert(new Vegetation(in_x, in_y));
            break;
        case 3:
            list.Insert(new Herbivore(in_x, in_y));
            break;
        case 4:
            list.Insert(new Carnivore(in_x, in_y));
            break;
        case 5:
            list.Insert(new Omnivore(in_x, in_y));
            break;
        default:
            return;
    }
    index++;
}

SinglyLinkedList &Map::getList() {
    return list;
}

void Map::place_blocks() {
    for(int i=0;i<12;i++){
        int rand_i = rand() % y;
        int rand_j = rand() % x;
        board[rand_i][rand_j] = 1;
    }
}