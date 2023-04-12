#include "Components/GameStart.h"
#include <random>
int main() {
    std::srand(time(nullptr));
    GameStart gameStart;
    gameStart.InitializeBoard().
    place_random_characters_at_random_locations_on_the_board().
    display();
}