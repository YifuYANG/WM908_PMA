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

    const string RESET = "\033[0m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";

    int x=0,y=0;

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

    void getX_Y(int x, int y);
};


#endif //PMA_MAP_H
