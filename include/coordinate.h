#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
    int getRow();
    int getCol();
    bool set(int row, int col);
private:
    int row;
    int col;
};

#endif