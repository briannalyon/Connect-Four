#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    Player(char token, bool isComputer, Board *board);
    void move();
    void manuallyPlace(int token);
    void randomlyPlace(int token);
    int getPlacement(int col); 
    Coordinate get();
    void outputBoard();
    bool hasWon(char token);
private:
    char token;
    bool isComputer;
    Board *board;
    
};

#endif