#ifndef PMA_SIMULATION_H
#define PMA_SIMULATION_H
#include "Map.h"
#include "Characters/Carnivore.h"


class Simulation {
private:
    Node* head;

    Map* initializedBoard = nullptr;

    int number_of_steps=-1;

    int random_number_generator(int range);

    Animal random_character_generator(int in_x, int in_y);

    void display_counter();

    void interaction(int next_x,int next_y, int pre_x, int pre_y);

    void loss_HP_due_to_being_consumed(Animal* animal);

    void loss_HP_due_to_hunger(Animal* animal);

    void get_HP_due_to_consuming(Animal* animal);

    void remove_animals_with_no_HP();

    Animal determine_parent_and_generator_offspring(Animal* animal);

    void random_select_spawn_point_in_one_of_the_four_cardinal_compass_points(Animal* animal);

    bool determine_if_there_are_spaces_for_reproduction(int x, int y);

public:
    Simulation();

    Simulation & InitializeBoard();

    Simulation & display();

    Simulation & place_random_characters_at_random_locations_on_the_board();

    Simulation & move_oneRound();

    Simulation & reproduction();
};


#endif //PMA_SIMULATION_H
