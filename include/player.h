#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    Player(char token, bool isComputer, Board *board);
    void move();
    void manuallyPlace(char token);
    void randomlyPlace(char token);
    int getPlacement(int col); 
    Coordinate get();
    void outputBoard();
    bool hasWon(char token);
private:
    char token;
    sf::Color color;
    bool isComputer;
    Board *board;
    
};

#endif