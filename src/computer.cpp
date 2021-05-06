#include "player.h"

/**
 * @brief Construct a new Computer object
 * 
 * @param board Game Board
 * @param token Computer's Token
 * @param isComputer Default true, player is a computer
 */
Computer::Computer(Board *board, char token, bool isComputer) {
    this->token = token;
    this->isComputer = isComputer;
    this->board = board;
}

/**
 * @brief Computer's turn, generates random input
 * 
 * @param event No event needed
 * @return int Status of turn
 */
int Computer::takeTurn(sf::Event &event) {
    move(0);
    if (hasWon()) {
        return 2;
    }
    return 1;
}

/**
 * @brief Delay's computer input
 * 
 */
void Computer::delay() {
    sleep(1);
}