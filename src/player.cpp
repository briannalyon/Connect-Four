#include "player.h"

    /**
     * @brief Construct a new Player:: Player object
     * 
     * @param token Player's token
     * @param isComputer determines if AI is needed
     * @param board Game board
     */
    Player::Player(char token, bool isComputer, Board *board) {
        this->token = token;
        this->isComputer = isComputer;
        this->board = board;
    }

    /**
     * @brief Determines if current player is a human or computer
     * 
     */
    void Player::move() {
        cout << "Placing Player Token" << endl;
        isComputer ? randomlyPlace(token) : manuallyPlace(token);
    }

    /**
     * @brief Calls functions to place token until successful
     *        and redisplay's the board to terminal
     * 
     * @param token Player's token
     */
    void Player::manuallyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;
        
        while (!placed) {
            coordinate = get();
            placed = board->placeToken(coordinate, token);
        }
        board->windowPlace(coordinate);
        board->display();
    }

    /**
     * @brief Calls functions to place token until successful
     *        and redisplay's the board to terminal
     * @param token Player's token
     */
    void Player::randomlyPlace(int token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;

        while (!placed) {
            coordinate = board->randomizeCoordinate();
            placed = board->placeToken(coordinate, token);
        }
        board->windowPlace(coordinate);
        board->display();
    }

    /**
     * @brief Retrieves Coordinate from player
     * 
     * @return Coordinate Column of choice and next avaiable row
     */
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

    /**
     * @brief Calls function to display board to terminal
     * 
     */
    void Player::outputBoard() {
        board->display();
    }

    /**
     * @brief Check to see if 4 tokens are connected
     * 
     * @param token Player's token
     * @return true Player has won
     * @return false No winner
     */
    bool Player::hasWon(char token) {
        return board->isConnected(token);
    }
