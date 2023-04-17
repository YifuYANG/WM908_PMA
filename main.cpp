#include "Components/Simulation.h"
#include "Container/SinglyLinkedList.h"
#include "Components/Characters/Carnivore.h"
#include <random>
#include "iostream"
using namespace std;

int main() {
    std::srand(time(nullptr));
//    for(int i=0;i<10000;i++){
//        Simulation gameStart;
//        gameStart.InitializeBoard().
//                place_random_characters_at_random_locations_on_the_board().
//                display().
//                move_oneRound().
//                move_oneRound().
//                move_oneRound().
//                display();
//    }

    Simulation simulation;
    simulation.InitializeBoard().
            place_random_characters_at_random_locations_on_the_board().
            display();

    for(int i=0;i<10;i++){
        simulation.move_oneRound().
                display();
    }

}