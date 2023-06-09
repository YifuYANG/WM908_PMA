#ifndef PMA_SIMULATION_H
#define PMA_SIMULATION_H
#include "Map.h"
#include "Characters/Carnivore.h"
#include"../Settings/Settings.h"
#include <iostream>
#include <fstream>
#include <string>

class Simulation {
private:
    Settings settings;

    Node* head;

    Map* initializedBoard = nullptr;

    int number_of_steps=-1;

    int random_number_generator(int range);

    Animal character_generator(int in_x, int in_y, int character);

    void display_counter();

    void interaction(int next_x,int next_y, int pre_x, int pre_y);

    void loss_HP_due_to_being_consumed(Animal* animal);

    void loss_HP_due_to_hunger(Animal* animal);

    void get_HP_due_to_consuming(Animal* animal);

    void remove_animals_with_no_HP();

    Animal determine_parent_and_generator_offspring(Animal* animal);

    void random_select_spawn_point_in_one_of_the_four_cardinal_compass_points(Animal* animal);

    bool determine_if_there_are_spaces_for_reproduction(int x, int y);

    void place_random_T_at_random_locations_on_the_board(int amount);

    void place_random_H_at_random_locations_on_the_board(int amount);

    void place_random_C_at_random_locations_on_the_board(int amount);

    void place_random_O_at_random_locations_on_the_board(int amount);

    int count_T();

    int count_H();

    int count_C();

    int count_O();

    void place_input_blocks_to_board(int x, int y);

    void place_input_T_to_board(int x, int y);

    void place_input_H_to_board(int x, int y);

    void place_input_C_to_board(int x, int y);

    void place_input_O_to_board(int x, int y);

public:
    int T_total=0;
    int C_total=0;
    int O_total=0;
    int H_total=0;

    Simulation();

    Simulation & InitializeBoard();

    Simulation & display();

    Simulation & place_random_characters_at_random_locations_on_the_board();

    Simulation & move_oneRound();

    Simulation & reproduction();

    Simulation & count_ave_character();

    Simulation & place_random_blocks();

    Simulation & Initialize_board_with_input_source();

    Simulation & save_map();

    Simulation & load_saved_map();
};


#endif //PMA_SIMULATION_H
