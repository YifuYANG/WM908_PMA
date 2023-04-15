#ifndef PMA_GAMESTART_H
#define PMA_GAMESTART_H
#include "Map.h"
#include "Characters/Carnivore.h"


class GameStart {
private:
    Map* initializedBoard = nullptr;

    int random_number_generator(int range);

public:
    GameStart();

    GameStart & InitializeBoard();

    GameStart & display();

    GameStart & place_random_characters_at_random_locations_on_the_board();

    GameStart & move_oneRound();

    void set_all_animal_to_has_not_moved();

};


#endif //PMA_GAMESTART_H
