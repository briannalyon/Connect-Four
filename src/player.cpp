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
    void Player::move(int col) {
        cout << "Placing Player Token" << endl;
        isComputer ? randomlyPlace(token) : manuallyPlace(token, col);
    }

    /**
     * @brief Calls functions to place token until successful
     *        and redisplay's the board to terminal
     * 
     * @param token Player's token
     */
    void Player::manuallyPlace(char token, int col) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;
        
        while (!placed) {
            coordinate = get(col);
            placed = board->placeToken(coordinate, token);
        }
    }


    /**
     * @brief Calls functions to place token until successful
     *        and redisplay's the board to terminal
     * @param token Player's token
     */
    void Player::randomlyPlace(char token) {
        Coordinate coordinate;
        this->token = token;
        bool placed = false;

        while (!placed) {
            coordinate = board->randomizeCoordinate();
            placed = board->placeToken(coordinate, token);
        }
    }

    /**
     * @brief Retrieves Coordinate from player
     * 
     * @return Coordinate Column of choice and next avaiable row
     */
    Coordinate Player::get(int col) {
        Coordinate coordinate;
        bool set = false;
        if (isComputer) {
            board->randomizeCoordinate();
        } else {
            while (!set) {
                //cout << "Enter valid column: ";
                // cin >> coordinate.col;
                coordinate.col = col - 1;
                coordinate.row = board->findAvailableRow(coordinate.col);
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