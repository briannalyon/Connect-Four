#include "player.h"

    Player::Player(char token) {
        this->token = token;
        isComputer = false;
    }

    Player::Player(char token, bool isComputer) {
        this->token = token;
        this->isComputer = isComputer;
    }

    void Player::manuallyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;
        
        while (!placed) {
            coordinate = get();
            placed = board.placeToken(coordinate, token);
            cout << "PLACED = " << placed << endl;
        }
        board.display();
    }

    void Player::randomlyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;

        while (!placed) {
            coordinate = board.randomizeCoordinate();
            placed = board.placeToken(coordinate, token);
        }
        board.display();
    }

    // bool Player::isAutomatic()
    //int Player::getPlacement(int col)

    void Player::move() {
        cout << "Placing Player Token" << endl;
        isComputer ? randomlyPlace(token) : manuallyPlace(token);
    }
     
    void Player::outputBoard() {
        board.display();
    }

    Coordinate Player::get() {
        Coordinate coordinate;
        bool set = false;
        if (isComputer) {
            board.randomizeCoordinate();
        } else {
            while (!set) {
                cout << "Enter valid column: ";
                cin >> coordinate.col;
                coordinate.row = board.findAvailableRow(coordinate.col);
                set = board.setCoordinate(coordinate.row, coordinate.col);
            }
        }
        return coordinate;
    }

    // void Player::move(Player *opponent) {
    //     bool registered = false;
    //     Coordinate choice;

    //     while (!registered) {
    //         choice = get();
    //         registered = opponent->registerMove(choice);
    //         // Print Error Here
    //     }
    // }

    bool Player::hasWon() {
        return board.isConnected();
    }

    //bool Player::registerMove()

    bool Player::registerMove(Coordinate coordinate) {
        bool check;
        board.placeToken(coordinate, token) ? check = true : check = false;
        return check;
    }
