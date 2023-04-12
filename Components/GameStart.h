#ifndef PMA_GAMESTART_H
#define PMA_GAMESTART_H
#include "Map.h"

class GameStart {
private:
    Map* initializedBoard = nullptr;
    int random_direction_generator();
    bool check_collision(int X, int Y);
    bool check_boundary(int X, int Y);
    int random_number_generator(int range);
public:
    GameStart();

    GameStart & InitializeBoard();

    GameStart & display();

    GameStart & place_random_characters_at_random_locations_on_the_board();

    GameStart & move_oneRound();


};


#endif //PMA_GAMESTART_H
