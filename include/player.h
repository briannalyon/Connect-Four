#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "coordinate.h"
#include <iostream>

class Player {
public:
    virtual int takeTurn(sf::Event &event) = 0;
    virtual void delay() = 0;
    void move(int col);
    void manuallyPlace(char token, int col);
    void randomlyPlace(char token);
    int getPlacement(int col); 
    Coordinate get(int col);
    void outputBoard();
    bool hasWon();
    void setCol(int col);
    char getToken();
protected:
    char token;
    sf::Color color;
    bool isComputer;
    Board *board;
};

class Human: public Player{
public: 
    Human(Board *board, char token='Y', bool isComputer=false);
    int takeTurn(sf::Event &event);
    void delay();
};

class Computer: public Player{
public: 
    Computer(Board *board, char token='R', bool isComputer=true);
    int takeTurn(sf::Event &event);
    void delay();
};
#endif