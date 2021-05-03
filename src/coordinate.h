/**
 * @file board.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
	int getRow();
    int getCol();
    int convertRow(char row);
    int convertCol(int col);
	bool set(char rowIn, int colIn);
    void display();

private:
    int row;
    int col;
};

#endif