/**
 * @file player.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include "player.h"
#include "coordinate.h"

Player::Player() {
    isComputer = false;
}

Player::Player(bool ic) {
    isComputer = ic;
}

void Player::manuallyPlaceToken(int token) {
    Coordinate coordinate;
    bool placed = false;
    while(!placed) {
        //coordinate = getCoordinate();
        placed = board.placeToken(coordinate, 'r');//fix later
    }
    board.display();
}
void Player::randomlyPlaceToken(int token) {
    // get random column
    Coordinate coordinate;
    bool placed = false;
    while(!placed) {
        coordinate.randomize();
        placed = board.placeToken(coordinate, 'r');//fix later
    }
    board.display();
}

void Player::placeToken()
{
    bool automatic = isAutomaticPlacement();
    Coordinate coordinate;
    int token;
    cout << endl << "Placing Player ___ Token\n";

    if (!automatic) {
        manuallyPlaceToken(token); 
    } else {
        randomlyPlaceToken(token);
    }
}

void Player::outputBoard() {
    board.display();
}

Coordinate Player::getCoordinate() {
    Coordinate coordinate;
    int row = '10';
    int col = -1;
    bool isSet = false;

    if (isComputer) {
        // ONLY RANDOMIZE COLUMN
        coordinate.randomize();
    } else {
        while(!isSet) {
            cout << "Enter the column: ";
            cin >> col;


            // GET NEXT AVAILABLE ROW SLOT


            isSet = coordinate.set(row, col);
        }
    }
    return coordinate;
}
