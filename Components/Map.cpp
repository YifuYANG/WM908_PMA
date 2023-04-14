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
bool Map::placeAt(Animal animal) {
    int X=animal.getX();
    int Y=animal.getY();
    int Character = animal.getCharacter();
    if(!check_boundary(X,Y)){
        return false;
    } else if(!check_collision(X,Y) && !list.checkByIndex(animal.getIndex())){
        return false;
    } else {
        store_animals_to_container(animal);
        board[X][Y] = Character;
        if (DISPLAY[Character] == " # ") {
            cout << "==> Placing block [" << DISPLAY[Character] << "] to coordinate [" << X+1 << " X " << Y+1 << "]" << endl;
        } else {
            cout << "==> Placing character [" << DISPLAY[Character] << "] to coordinate [" << X+1 << " X " << Y+1 << "]" << endl;
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
    return board[input_X][input_Y] == 0;
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

void Map::store_animals_to_container(Animal animal) {
    Animal* newanimal;
    switch (animal.getCharacter()) {
        case 2:
            newanimal = new Vegetation(animal.getX(), animal.getY(), index);
            break;
        case 3:
            newanimal = new Herbivore(animal.getX(), animal.getY(), index);
            break;
        case 4:
            newanimal = new Carnivore(animal.getX(), animal.getY(), index);
            break;
        case 5:
            newanimal = new Omnivore(animal.getX(), animal.getY(), index);
            break;
        default:
            return;
    }

    if(list.checkByIndex(animal.getIndex())){
        newanimal->setIndex(animal.getIndex());
        newanimal->setWhetherThisAnimalHasMovedOrNot(true);
        list.ReplaceByIndex(animal.getIndex(),newanimal);
    } else {
        list.Insert(newanimal);
        index++;
    }
}

SinglyLinkedList &Map::getList() {
    return list;
}