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
            get();
            placed = board.placeToken(coordinate, token);
        }
        board.display();
    }

    void Player::randomlyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;

        while (!placed) {
            board.randomizeCoordinate();
            placed = board.placeToken(coordinate, token);
        }
        board.display();
    }

    // bool Player::isAutomatic()
    //int Player::getPlacement(int col)

    void Player::placeToken(int token) {
        bool automatic = isComputer;
        cout << "Placing Player Token" << endl;
        (!automatic) ? manuallyPlace(token) : randomlyPlace(token);
    }
     
    void Player::outputBoard() {
        board.display();
    }

    Coordinate Player::get() {
        Coordinate coordinate;
        int row, col = -1;
        bool set = false;

        if (isComputer) {
            board.randomizeCoordinate();
        } else {
            while (!set) {
                cout << "Enter valid column: ";
                cin >> col;
                row = board.findAvailableRow(col);
                set = board.setCoordinate(row, col);
            }
        }
        return coordinate;
    }

    void Player::move(Player *opponent) {
        bool registered = false;
        Coordinate choice;

        while (!registered) {
            choice = get();
            registered = opponent->registerMove(choice);
            // Print Error Here
        }
    }

    bool Player::hasWon() {
        return board.isConnected();
    }

    //bool Player::registerMove()

    bool Player::registerMove(Coordinate coordinate) {
        bool check;
        board.placeToken(coordinate, token) ? check = true : check = false;
        return check;
    }
