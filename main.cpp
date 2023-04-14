#include "Components/GameStart.h"
#include "Container/SinglyLinkedList.h"
#include "Components/Characters/Carnivore.h"
#include <random>
#include "iostream"
using namespace std;

int main() {
    std::srand(time(nullptr));
    for(int i=0;i<100;i++){
        cout<< "i===============================> "<<i+1<<endl;
        GameStart gameStart;
        gameStart.InitializeBoard().
                place_random_characters_at_random_locations_on_the_board().
                display().
                move_oneRound().
                display();
    }


}