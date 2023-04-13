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

GameStart & GameStart::move_oneRound() {
    board_refresher();
    for(int i=1;i<=initializedBoard->getList().GetSize();i++){
        initializedBoard->getList().getByIndex(i)->getData();

    }
    return *this;
}


GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<15; i++){
        int rand_X=random_number_generator(initializedBoard->getY());
        int rand_Y=random_number_generator(initializedBoard->getX());
        initializedBoard->placeAt(rand_X,rand_Y,rand() % 5+1);
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



