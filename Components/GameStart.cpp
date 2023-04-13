#include "GameStart.h"
#include "../Components/Characters/Animal.h"
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
                if (direction == 1 && check_collision(i,j+1) && check_boundary(i,j+1)) {
                    initializedBoard->board[i][j+1]=initializedBoard->board[i][j];
                    initializedBoard->board[i][j]=0;
                } else if (direction == 2 && check_collision(i,j-1) && check_boundary(i,j-1)) {
                    initializedBoard->board[i][j-1]=initializedBoard->board[i][j];
                    initializedBoard->board[i][j]=0;
                } else if (direction == 3 && check_collision(i+1,j) && check_boundary(i+1,j)) {
                    initializedBoard->board[i+1][j]=initializedBoard->board[i][j];
                    initializedBoard->board[i][j]=0;
                    //cout<<i<<"--"<<j<<endl;
                } else if (direction == 4 && check_collision(i-1,j) && check_boundary(i-1,j)) {
                    initializedBoard->board[i-1][j]=initializedBoard->board[i][j];
                    initializedBoard->board[i][j]=0;
                }
            }
        }
    }
    return *this;
}

//case: position is not empty, wouldn't generate 15 c
GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<15; i++){
        int rand_X=random_number_generator(initializedBoard->getY());
        int rand_Y=random_number_generator(initializedBoard->getX());
        initializedBoard->placeAt(rand_X,rand_Y,rand() % 6+1);
    }
    return *this;
}

bool GameStart::check_collision(int X, int Y) {
    return initializedBoard->board[X][Y]==0;
}

bool GameStart::check_boundary(int X, int Y) {
    return X+1 <= initializedBoard->getY() && Y+1 <= initializedBoard->getX();
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


