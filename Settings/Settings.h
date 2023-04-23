#ifndef PMA_SETTINGS_H
#define PMA_SETTINGS_H

#include "iostream"
using namespace std;
class Settings {
public:
    //map settings
    int X = 14;
    int Y = 14;
    int Blocks = 12;
    //characters settings
    int T = 20;
    int H = 20;
    int C = 20;
    int O = 10;

    int T_HP = 100;
    int H_HP = 50;
    int C_HP = 50;
    int O_HP = 50;

    int T_MP = 0;
    int H_MP = 5;
    int C_MP = 5;
    int O_MP = 8;

    //second solution for simulating a balance environment
//    double FR_T = 0.05;
//    double FR_H = 0.05;
//    double FR_C = 0.001;
//    double FR_O = 0.015;

    double FR_T = 0.03;
    double FR_H = 0.03;
    double FR_C = 0.03;
    double FR_O = 0.03;

    int amount_of_HP_lost = 10;
    //simulation settings
    int steps = 1000000;
    int number_of_simulations = 100;
};
#endif //PMA_SETTINGS_H
