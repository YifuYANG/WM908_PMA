#ifndef PMA_GAMESTART_H
#define PMA_GAMESTART_H
#include "Map.h"

class GameStart {
private:
    Map* initializedBoard = nullptr;
    int random_direction_generator();
public:
    GameStart();

    GameStart & InitializeBoard();

    GameStart & display();

    GameStart & place_random_characters_at_random_locations_on_the_board();

    GameStart & move_oneRound();


};


#endif //PMA_GAMESTART_H
