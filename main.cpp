#include <iostream>
#include "Components/Map.h"
#include "Settings/Movement_Settings.h"
#include <random>
int main() {
    int **board;
    std::srand(time(nullptr));
    Map map(10,7);
    Movement_Settings move;
    cout<< "=================================================="<<endl;
//    for(int i=0;i<2;i++){
//        map.rand_place((rand() % 5)+1);
//    }
    map.placeAt(5,5,2);
    map.placeAt(5,4,2);
    map.placeAt(5,3,2);
    map.placeAt(7,10,1);
    cout<< "=================================================="<<endl;
    map.display();
    cout<<"=================================================="<<endl;
    move.move_oneRound(map);
    map.display();
    cout<<"=================================================="<<endl;
}