#ifndef PMA_MAP_H
#define PMA_MAP_H
#include "iostream"
//#include "../Components/Characters/Animal.h"
using namespace std;
class Map {
private :
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
    bool placeAt(int input_X, int input_Y, int character);
    string getXY(int input_X,int input_Y);
    int getX() const;
    int getY() const;
};


#endif //PMA_MAP_H
