#include "Components/GameStart.h"
#include "Components/Characters/Animal.h"
#include "Components/Characters/Herbivore.h"
#include <random>
#include "iostream"
using namespace std;

int main() {
    std::srand(time(nullptr));
//    GameStart gameStart;
//    gameStart.InitializeBoard().
//    place_random_characters_at_random_locations_on_the_board().
//    display();
    Herbivore c;
    cout<<c.getMp()<<endl;
}