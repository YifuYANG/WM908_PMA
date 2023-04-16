#ifndef PMA_GAMESTART_H
#define PMA_GAMESTART_H
#include "Map.h"
#include "Characters/Carnivore.h"


class GameStart {
private:
    Map* initializedBoard = nullptr;

    int number_of_steps=-1;

    int random_number_generator(int range);

    void set_all_animal_to_has_not_moved();

    Animal& random_character_generator(int in_x, int in_y);

    void display_counter();

    void interaction(int next_x,int next_y, int pre_x, int pre_y);

    void loss_HP_due_to_being_consumed(Animal* animal);

    void loss_HP_due_to_hunger(Animal* animal);

    void remove_animals_with_no_HP();

public:
    GameStart();

    GameStart & InitializeBoard();

    GameStart & display();

    GameStart & place_random_characters_at_random_locations_on_the_board();

    GameStart & move_oneRound();
};


#endif //PMA_GAMESTART_H
