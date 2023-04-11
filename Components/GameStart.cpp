#include "GameStart.h"

GameStart::GameStart() = default;

/* helper function for move:
 * generate a random number between 1 - 4,
 * 1 -> move to East,
 * 2 -> move to West,
 * 3 -> move to South,
 * 4 -> move to North.
 * */
int GameStart::random_direction_generator() {
    return (rand() % 4)+1;
}

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
    for(int i=0;i<initializedBoard->getY();i++){
        for(int j=0;j<initializedBoard->getX();j++){
            if(initializedBoard->board[i][j]==0 || initializedBoard->board[i][j]==1){
                continue;
            } else {
                int direction = random_direction_generator();
                if (direction == 1 && j < initializedBoard->getX() - 1) {
                    swap(initializedBoard->board[i][j], initializedBoard->board[i][j+1]);
                } else if (direction == 2 && j > 0) {
                    swap(initializedBoard->board[i][j], initializedBoard->board[i][j-1]);
                } else if (direction == 3 && i < initializedBoard->getY() - 1) {
                    swap(initializedBoard->board[i][j], initializedBoard->board[i+1][j]);
                } else if (direction == 4 && i > 0) {
                    swap(initializedBoard->board[i][j], initializedBoard->board[i-1][j]);
                }
            }
        }
    }
    return *this;
}

GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
//    for(int i=0;i<7; i++){
//        initializedBoard->rand_place(rand() % 6+1);
//    }
    initializedBoard->rand_place(rand() % 6+1);
    return *this;
}


