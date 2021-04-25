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
	bool set(char rowIn, int colIn);
    void randomize();
    void display();
    int findAvaiableRow(int col);

private:
    int convertRow(char row);
    int convertCol(int col);
    int row;
    int col;
    Board board;
};

#endif