#include "player.h"

    Player::Player(char token) {
        this->token = token;
        isComputer = false;
    }

    Player::Player(char token, bool isComputer, Board *board) {
        this->token = token;
        this->isComputer = isComputer;
        this->board = board;
    }

    void Player::manuallyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;
        
        while (!placed) {
            coordinate = get();
            placed = board->placeToken(coordinate, token);
            // here
        }
        board->display();
    }

    void Player::randomlyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;

        while (!placed) {
            coordinate = board->randomizeCoordinate();
            placed = board->placeToken(coordinate, token);
        }
        board->display();
    }

    // bool Player::isAutomatic()
    //int Player::getPlacement(int col)

    void Player::move() {
        cout << "Placing Player Token" << endl;
        isComputer ? randomlyPlace(token) : manuallyPlace(token);
    }
     
    void Player::outputBoard() {
        board->display();
    }

    Coordinate Player::get() {
        Coordinate coordinate;
        bool set = false;
        if (isComputer) {
            board->randomizeCoordinate();
        } else {
            while (!set) {
                cout << "Enter valid column: ";
                cin >> coordinate.col;
                coordinate.col = coordinate.col - 1;
                coordinate.row = board->findAvailableRow(coordinate.col);
                cout << "ROW: " << coordinate.row << endl;
                set = board->setCoordinate(coordinate.row, coordinate.col);
            }
        }
        return coordinate;
    }

    bool Player::hasWon() {
        return board->isConnected();
    }
