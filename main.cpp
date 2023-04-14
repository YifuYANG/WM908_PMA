#include "Components/GameStart.h"
#include "Container/SinglyLinkedList.h"
#include "Components/Characters/Carnivore.h"
#include <random>
#include "iostream"
using namespace std;

int main() {
    std::srand(time(nullptr));
    GameStart gameStart;
    gameStart.InitializeBoard().
    place_random_characters_at_random_locations_on_the_board().
    display().
    move_oneRound().
    display();

    //gameStart.printList();
//    SinglyLinkedList list;
//    for(int i=0;i<5;i++){
//        list.Insert(new Animal (i,i+2,i+1));
//    }
//    list.printList();
//    cout<<list.getByIndex(5)->getData()->getX()<<" X "<<list.getByIndex(5)->getData()->getY();
}