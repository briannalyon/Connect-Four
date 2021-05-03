#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
using std::cout;
using std::endl;

struct Coordinate {
    int row;
    int col;
    void set(int row, int col);
};

#endif