#include <iostream>
#include "Component/Map.h"
#include <random>
int main() {
    std::srand(time(nullptr));
    Map map(10,7);
    for(int i=0;i<5;i++){
        map.place(1);
    }
    map.display();
    cout<<map.getXY(1,7)<<endl;
}
