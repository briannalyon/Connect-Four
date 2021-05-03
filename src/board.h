/**
 * @file game.h
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "coordinate.h"
using namespace std;

const int ROWSIZE = 6;
const int COLSIZE = 7;

class Board
{
    public:
        Board();
        void display();
        bool placeToken(Coordinate, char tokenColor);
        bool isClear(Coordinate coordinate);
        bool isInBounds(Coordinate coordinate);
        bool isEmpty(Coordinate coordinate);
        void updateBoard(Coordinate coordinate, char tokenColor);
        char getColor(Coordinate coordinate);
        void randomizeCoordinate();
        bool setCoordinate(char rowIn, int colIn);
        int findAvaiableRow(int col);
        bool fourConnected();
    private:
        char board[ROWSIZE][COLSIZE];
};
#endif