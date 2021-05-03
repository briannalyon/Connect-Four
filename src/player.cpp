/**
 * @file player.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include "player.h"

Player::Player() {
    isComputer = false;
}

Player::Player(bool ic) {
    isComputer = ic;
}

void Player::manuallyPlaceToken(int token) {
    Coordinate coordinate;
    token = 'r'; // temp
    bool placed = false;
    while(!placed) {
        //coordinate = getCoordinate();
        placed = board.placeToken(coordinate, token);//fix later
    }
    board.display();
}
void Player::randomlyPlaceToken(int token) {
    // get random column
    Coordinate coordinate;
    token = 'r';
    bool placed = false;
    while(!placed) {
        board.randomizeCoordinate();
        placed = board.placeToken(coordinate, token);//fix later
    }
    board.display();
}

void Player::placeToken()
{
    bool automatic = true;//isAutomaticPlacement();
    //Coordinate coordinate;
    int token = 'r';
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
    int row = -1;
    int col = -1;
    bool isSet = false;

    if (isComputer) {
        board.randomizeCoordinate();
    } else {
        while(!isSet) {
            cout << "Enter the column: ";
            cin >> col;
            row = board.findAvaiableRow(col);
            isSet = board.setCoordinate(row, col);
        }
    }
    return coordinate;
}

void Player::move(Player *opponent)
{
    bool registered = false;
    Coordinate choice;
    
    while(! registered) {
        choice = getCoordinate();
        registered = opponent->registerMove(choice);
        // print out errosr if not registered
    }
}

bool Player::registerMove(Coordinate coordinate)
{
    if (board.placeToken(coordinate, 'r')) {
        return true;
    }
    return false;
}

bool Player::hasLost()
{
    return board.fourConnected();
}