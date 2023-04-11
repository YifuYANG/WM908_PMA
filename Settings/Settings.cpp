#include "Settings.h"
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

void Settings::move_oneRound(Map map) {
    for(int i=0;i<map.getY();i++){
        for(int j=0;j<map.getX();j++){
            if(map.board[i][j]==0 || map.board[i][j]==1){
                continue;
            } else {
                int direction = random_direction_generator();
                if (direction == 1 && j < map.getX() - 1) {
                    swap(map.board[i][j], map.board[i][j+1]);
                } else if (direction == 2 && j > 0) {
                    swap(map.board[i][j], map.board[i][j-1]);
                } else if (direction == 3 && i < map.getY() - 1) {
                    swap(map.board[i][j], map.board[i+1][j]);
                } else if (direction == 4 && i > 0) {
                    swap(map.board[i][j], map.board[i-1][j]);
                }
            }
        }
    }
}

/* helper function for move:
 * generate a random number between 1 - 4,
 * 1 -> move to East,
 * 2 -> move to West,
 * 3 -> move to South,
 * 4 -> move to North.
 * */
int Settings::random_direction_generator() {
    return (rand() % 4)+1;
}

bool Settings::rule_stopMoving(int current_X, int current_Y, int next_X, int next_Y, int board_X, int board_Y) {
//    if(current_X>board_X-1){
//        return false;
//    } else if(current_Y>board_Y-1){
//        return false;
//    } else if(){
//
//    }
}