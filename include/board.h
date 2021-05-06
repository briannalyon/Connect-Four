#ifndef BOARD_H
#define BOARD_H

#include "coordinate.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <cmath>
#include <unistd.h>
using std::cout;
using std::endl;
using std::cin;

const int ROWSIZE = 6;
const int COLSIZE = 7;

class Board {
public:
    Board();
    void display();
    bool placeToken(Coordinate coordinate, char token);
    bool isClear(Coordinate coordinate);
    bool inBounds(Coordinate coordinate);
    void updateBoard(Coordinate coordinate, char token);
    Coordinate randomizeCoordinate();
    bool setCoordinate(int row, int col);
    int findAvailableRow(int col);
    bool isConnected(char token);
    void setPlayer(char token);

    // ---- SFML FUNCTIONS ---- //

    sf::RenderWindow* getWindow();
    void intitalize();
    void render();
    
private:
    char board[ROWSIZE][COLSIZE];
    sf::RenderWindow window;
    const sf::Color background = sf::Color(200, 200, 200, 255);
    const sf::Color tokenOutline = sf::Color(0, 51, 102, 255);
    char currPlayer;
    sf::Font font;
    sf::Text num;
    sf::Text playerOne;
    sf::Text playerTwo;
    sf::Text playerOneWin;
    sf::Text playerTwoWin;
    sf::RectangleShape header;
    sf::CircleShape emptyToken;
    sf::CircleShape redToken;
    sf::CircleShape yellowToken;
};
#endif