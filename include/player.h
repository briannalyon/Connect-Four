#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    Player(char token);
    Player(char token, bool isComputer, Board *board);
    void manuallyPlace(int token);
    void randomlyPlace(int token);
    int getPlacement(int col);
    void move(); 
    void outputBoard();
    Coordinate get();
    bool hasWon();
private:
    Board *board;
    char token;
    bool isComputer;
};

#endif