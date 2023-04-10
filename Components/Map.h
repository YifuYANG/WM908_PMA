#ifndef PMA_MAP_H
#define PMA_MAP_H
#include "iostream"
using namespace std;
class Map {
private :
    int x,y;
    //block (#), vegetation (T), herbivore (H), carnivore (C), omnivore (O), hunter (R)
    const string DISPLAY [7] = {"   "," # "," T ", " H "," C "," O ", " R "};
    //private helper functions
    bool check_collision(int input_X,int input_Y);
    bool check_boundary(int input_X, int input_Y);
    int random_number_generator(int range);
public:
    int **board;
    Map(int x, int y);
    ~Map();
    void display();
    void rand_place(int character);
    void placeAt(int input_X, int input_Y, int character);
    string getXY(int input_X,int input_Y);
    int getX() const;
    int getY() const;
};


#endif //PMA_MAP_H
