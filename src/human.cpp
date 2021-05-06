    #include "player.h"

    /**
     * @brief Construct a new Human:: Human object
     * 
     * @param board Game Board
     * @param token Human Player's Token
     * @param isComputer Default false - Human is not a computer
     */
    Human::Human(Board *board, char token, bool isComputer) {
        this->token = token;
        this->isComputer = isComputer;
        this->board = board;
    }
    
    /**
     * @brief Human Player's turn determines if key is pressed
     * 
     * @param event Key pressed by user
     * @return int Status of turn
     */
    int Human::takeTurn(sf::Event &event) {
        int col = -1;
        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::Num1) col = 1;
            else if (event.key.code == sf::Keyboard::Num2) col = 2;
            else if (event.key.code == sf::Keyboard::Num3) col = 3;
            else if (event.key.code == sf::Keyboard::Num4) col = 4;
            else if (event.key.code == sf::Keyboard::Num5) col = 5;
            else if (event.key.code == sf::Keyboard::Num6) col = 6;
            else if (event.key.code == sf::Keyboard::Num7) col = 7;

            if (col != -1) {
                move(col);

                if (hasWon()) {
                    return 2;
                }
                return 1;
            }   
        } 
        return 0;
    }

    /**
     * @brief No delay needed for human player set to 0
     * 
     */
    void Human::delay() {
        sleep(0);
    }