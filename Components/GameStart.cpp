#include "GameStart.h"


GameStart::GameStart() = default;


GameStart &GameStart::InitializeBoard() {
    this->initializedBoard = new Map(10,7);
    return *this;
}

GameStart &GameStart::display() {
    if(this->initializedBoard != nullptr) {
        this->initializedBoard->display();
    }
    //counter display
    return *this;
}

GameStart& GameStart::move_oneRound() {
    board_refresher();
    for (int i = 1; i <= initializedBoard->getList().GetSize(); i++) {
        Animal& animal = *initializedBoard->getList().getByIndex(i)->getData();
        int x = animal.getX();
        int y = animal.getY();
        if (!animal.isWhetherThisAnimalHasMovedOrNot()) {
            while (true) {
                cout<<"Old X: "<<x<<" Old Y: "<<y<<endl;
                animal.move();
                cout<<"New X: "<<animal.getX()<<" New Y: "<<animal.getY()<<endl;
                if (initializedBoard->placeAt(animal)) {
                    break;
                }
                animal.setX(x);
                animal.setY(y);
            }
        }
    }
    return *this;
}

GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<20; i++){
        int rand_X;
        int rand_Y;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
        } while(!initializedBoard->placeAt(*new Carnivore(rand_X,rand_Y)));
        initializedBoard->placeAt(*new Carnivore(rand_X,rand_Y));
    }
    return *this;
}

/* helper function for place_random_characters_at_random_locations_on_the_board:
 * generate a random number in the range of given bounds,
 * for example: given range -> 1 - 10,
 * it will generate number -> 0 - 9,
 * which corresponds to the array index.
 * */
int GameStart::random_number_generator(int range) {
    return rand() % range;
}

void GameStart::printList() {
    SinglyLinkedList list=this->initializedBoard->getList();
    list.printList();
}

void GameStart::board_refresher() {
    for(int i=0;i<initializedBoard->getY();i++){
        for(int j=0;j<initializedBoard->getX();j++){
            if(initializedBoard->board[i][j]==0 || initializedBoard->board[i][j]==1){
                continue;
            } else {
                initializedBoard->board[i][j]=0;
            }
        }
    }
}



