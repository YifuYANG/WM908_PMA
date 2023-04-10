#ifndef PMA_MOVEMENT_SETTINGS_H
#define PMA_MOVEMENT_SETTINGS_H

#include "iostream"
#include "../Components/Map.h"
using namespace std;
class Movement_Settings {
private:
    enum MP {
        East = 0,
        West = 1,
        South = 2,
        North = 3
    };
int random_direction_generator();

public:
    void move_oneRound(Map map);
    bool rule_stopMoving(int current_X, int current_Y, int next_X,int next_Y,int board_X, int board_Y);
};


#endif //PMA_MOVEMENT_SETTINGS_H
