#ifndef BOARD_H
#define BOARD_H

#include "coordinate.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

const int ROWSIZE = 6;
const int COLSIZE = 7;

class Board {
public:
    Board();
    sf::RenderWindow* getWindow();
    void intitalize();
    void render();
    void display();
    bool placeToken(Coordinate coordinate, char token);
    bool isClear(Coordinate coordinate);
    bool inBounds(Coordinate coordinate);
    void updateBoard(Coordinate coordinate, char token);
    //char getTokenColor(Coordinate coordinate);
    Coordinate randomizeCoordinate();
    bool setCoordinate(int row, int col);
    int findAvailableRow(int col);
    bool isConnected(char token);
private:
    char board[ROWSIZE][COLSIZE];
    sf::RenderWindow window;
};

#endif