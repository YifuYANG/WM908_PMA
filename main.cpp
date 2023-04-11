#include <iostream>
#include "Components/Map.h"
#include "Components/GameStart.h"
#include "Settings/Settings.h"
#include <random>
int main() {
    std::srand(time(nullptr));
//    Map map(10,7);
//    Settings move;
//    cout<< "=================================================="<<endl;
//    map.placeAt(5,5,2);
//    map.placeAt(5,4,2);
//    map.placeAt(5,3,2);
//    map.placeAt(7,10,1);
//    cout<< "=================================================="<<endl;
//    map.display();
//    cout<<"=================================================="<<endl;
//    move.move_oneRound(map);
//    map.display();
//    cout<<"=================================================="<<endl;
    GameStart gameStart;
    gameStart.InitializeBoard().
    place_random_characters_at_random_locations_on_the_board().
    display().
    move_oneRound().
    display();
}