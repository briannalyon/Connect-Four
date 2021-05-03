#ifndef BOARD_H
#define BOARD_H

#include "coordinate.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

const int ROWSIZE = 6;
const int COLSIZE = 7;

class Board {
public:
    Board();
    void display();
    bool placeToken(Coordinate coordinate, char token);
    bool isClear(Coordinate coordinate);
    bool inBounds(Coordinate coordinate);
    void updateBoard(Coordinate coordinate, char token);
    //char getTokenColor(Coordinate coordinate);
    void randomizeCoordinate();
    bool setCoordinate(int row, int col);
    int findAvailableRow(int col);
    bool isConnected();
private:
    char board[ROWSIZE][COLSIZE];
};

#endif