#include <iostream>
#include "Component/Map.h"
#include <random>
int main() {
    std::srand(time(nullptr));
    Map map(10,7);
//    for(int i=0;i<50;i++){
//        map.rand_place(1);
//    }
    map.placeAt(7,10,1);
    map.placeAt(7,10,1);
    map.display();
    cout<<"==> Target Acquired -> "<<map.getXY(7,10)<<endl;
}
