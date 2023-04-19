#ifndef PMA_MAP_H
#define PMA_MAP_H
#include "iostream"
#include "../Container/SinglyLinkedList.h"
#include <random>
#include <iomanip>
#include "Characters/Vegetation.h"
#include "Characters/Herbivore.h"
#include "Characters/Carnivore.h"
#include "Characters/Omnivore.h"
#include "../Settings/Settings.h"
using namespace std;
class Map {
private :
    Settings settings;

    SinglyLinkedList list;

    int x=0,y=0;

    int index=1;

    //block (#), vegetation (T), herbivore (H), carnivore (C), omnivore (O), hunter (R)
    const string DISPLAY [7] = {"   "," # "," T ", " H "," C "," O ", " R "};

    //private helper functions
    bool check_collision(int input_X,int input_Y);

    bool check_boundary(int input_X, int input_Y);

public:

    int **board;

    Map(int x, int y);

    ~Map();

    void display();

    bool placeAt(Animal animal);

    bool getXY(int input_X,int input_Y);

    int getX() const;

    int getY() const;

    SinglyLinkedList &getList();

    void store_animals_to_container(int character, int x, int y);
};


#endif //PMA_MAP_H
