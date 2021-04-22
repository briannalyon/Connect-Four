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

bool Coordinate::set(char rowIn, int colIn) {
    int r = findAvaiableRow(colIn);
    int c = convertCol(colIn);

    if (r == -1) {
        cout << "Invalid row character " << rowIn << endl;
        return false;
    }
    if (c == -1) {
        cout << "Invalid column value " << colIn << endl;
        return false;
    }
    row = r;
    col = c;
    return true;
}

void Coordinate::randomize() {
    int col = 1 + rand() % 10;
    row = findAvaiableRow(col);
    set(row, col);
}

void Coordinate::display()
{
    cout << "You chose column: " << col << endl;
    cout << "Next row available:  " << row << endl;
}

int Coordinate::convertRow(char row) {
    if (col >= 1 && col <= 7) {
        return --col;
    }
    return -1;
}

int Coordinate::convertCol(int col) {
    if (col >= 1 && col <= 6) {
        return --col;
    }
    return -1;
}

int findAvaiableRow(int col) {

    // FIND ROW
}