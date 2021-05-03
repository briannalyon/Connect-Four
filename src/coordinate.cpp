/**
 * @file board.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include "coordinate.h"
#include "board.h"
#include "player.h"

int Coordinate::getRow() {
    return row;
}

int Coordinate::getCol() {
    return col;
}

int Coordinate::convertRow(char row) {
    if (row >= 1 && row <= 7) {
        return --row;
    }
    return -1;
}

int Coordinate::convertCol(int col) {
    if (col >= 1 && col <= 6) {
        return --col;
    }
    return -1;
}

bool Coordinate::set(char rowIn, int colIn) {
    row = rowIn;
    col = colIn;
    return true;
}

void Coordinate::display()
{
    cout << "You chose column: " << col << endl;
    cout << "Next row available:  " << row << endl;
}