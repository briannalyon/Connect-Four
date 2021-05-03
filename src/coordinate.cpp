#include "coordinate.h"

int Coordinate::getRow() {
    return row;
}

int Coordinate::getCol() {
    return col;
}

bool Coordinate::set(int row, int col) {
    this->row = row;
    this->col = col;
    return true; // true if set properly
}