#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    Player(char token, bool isComputer, Board *board);
    void move(int col);
    void manuallyPlace(char token, int col;
    void randomlyPlace(char token);
    int getPlacement(int col); 
    Coordinate get(int col);
    void outputBoard();
    bool hasWon(char token);
    void setCol(int col)
private:
    char token;
    // int col;
    sf::Color color;
    bool isComputer;
    Board *board;
    
};

#endif