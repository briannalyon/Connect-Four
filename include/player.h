#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    Player(char token);
    Player(char token, bool isComputer);
    void manuallyPlace(int token);
    void randomlyPlace(int token);
    // bool isAutomatic()
    int getPlacement(int col);
    void move(); 
    void outputBoard();
    Coordinate get();
    //void move(Player *opponent);
    bool hasWon();
    bool registerMove();
    bool registerMove(Coordinate coordinate);
private:
    Board board;
    char token;
    bool isComputer;
};

#endif