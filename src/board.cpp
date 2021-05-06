#include "board.h"

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board() {
    for (int row = 0; row < ROWSIZE; ++row) {
        for (int col = 0; col < COLSIZE; ++col) {
            board[row][col] = 'O';
        }
    }

    if (!font.loadFromFile("assets/OpenSans-Bold.ttf")) {
        cout << "File cannot load" << '\n';
    }

    num.setFont(font);
    num.setString("         1               2              3               4              5               6               7 ");
    num.setCharacterSize(30);
    num.setStyle(sf::Text::Bold);
    num.setFillColor(sf::Color(0, 76, 153, 255));
    num.setPosition(0, 50);

    playerOne.setFont(font);
    playerOne.setString("Player 1");
    playerOne.setCharacterSize(30);
    playerOne.setStyle(sf::Text::Bold);
    playerOne.setFillColor(sf::Color(247, 207, 74, 255));
    playerOne.setPosition(0, 0);

    playerTwo.setFont(font);
    playerTwo.setString("Player 2");
    playerTwo.setCharacterSize(30);
    playerTwo.setStyle(sf::Text::Bold);
    playerTwo.setFillColor(sf::Color(216, 28, 28, 255));
    playerTwo.setPosition(0, 0);

    playerOneWin.setFont(font);
    playerOneWin.setString("Wins!!!");
    playerOneWin.setCharacterSize(30);
    playerOneWin.setStyle(sf::Text::Bold);
    playerOneWin.setFillColor(sf::Color(216, 28, 28, 255));
    playerOneWin.setPosition(135, 0);

    playerTwoWin.setFont(font);
    playerTwoWin.setString("Wins!!!");
    playerTwoWin.setCharacterSize(30);
    playerTwoWin.setStyle(sf::Text::Bold);
    playerTwoWin.setFillColor(sf::Color(247, 207, 74, 255));
    playerTwoWin.setPosition(135, 0);

    header.setSize(sf::Vector2f(2400.f, 200.f));
    header.setFillColor(background);
    header.setOrigin(header.getSize().x / 2, header.getSize().y / 2);
    header.setOutlineThickness(5);
    header.setOutlineColor(tokenOutline);

    emptyToken.setRadius(50.f);
    emptyToken.setFillColor(background);
    emptyToken.setOutlineThickness(5);
    emptyToken.setOutlineColor(tokenOutline);

    redToken.setRadius(50.f);
    redToken.setFillColor(sf::Color(216, 28, 28, 255));
    redToken.setOutlineThickness(5);
    redToken.setOutlineColor(tokenOutline);

    yellowToken.setRadius(50.f);
    yellowToken.setFillColor(sf::Color(247, 207, 74, 255));
    yellowToken.setOutlineThickness(5);
    yellowToken.setOutlineColor(tokenOutline);

    intitalize();
    render();
}

/**
 * @brief Display's the board to terminal
 * 
 */
void Board::display() {
    cout << "1 2 3 4 5 6 7" << endl;
    for (int row = 0; row < ROWSIZE; ++row) {
        for (int col = 0; col < COLSIZE; ++col) {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Places the player token in given coordinate
 * 
 * @param coordinate 
 * @param token 
 * @return true 
 * @return false 
 */
bool Board::placeToken(Coordinate coordinate, char token) {
    int row = coordinate.row;
    int col = coordinate.col;
    if (!inBounds(coordinate) || !isClear(coordinate)) {
        return false;
    }
    board[row][col] = token;
    return true;
}

/**
 * @brief 
 * 
 * @param coordinate 
 * @return true 
 * @return false 
 */
bool Board::isClear(Coordinate coordinate) {
    int row = coordinate.row;
    int col = coordinate.col;
    bool check;
    (board[row][col] != 'O') ? check = false : check = true;
    return check;
}

/**
 * @brief Checks to see if coordinate is on the board
 * 
 * @param coordinate 
 * @return true 
 * @return false 
 */
bool Board::inBounds(Coordinate coordinate) {
    int row = coordinate.row;
    int col = coordinate.col;
    bool check;
    ((col > COLSIZE - 1 || col < 0) || (row > ROWSIZE - 1 || row < 0)) ? check = false : check = true;
    return check;
}

/**
 * @brief Updates the board with player's token
 * 
 * @param coordinate Coordinate to be updated
 * @param token Player's Token
 */
void Board::updateBoard(Coordinate coordinate, char token) {
    int row = coordinate.row;
    int col = coordinate.col;
    board[row][col] = token;
}

/**
 * @brief Randomizes a column from 1 - 7 and retrieves the next 
 *        available row
 * 
 * @return Coordinate Returns the randomized coordinate
 */
Coordinate Board::randomizeCoordinate() {
    Coordinate coordinate;
    int col = rand() % COLSIZE;
    cout << "Random Col: " << col << endl;
    coordinate.set(findAvailableRow(col), col);
    return coordinate;
}

/**
 * @brief Calls member function in class Coordinate to set member
 *        variables row and col
 * 
 * @param row 
 * @param col 
 * @return true 
 * @return false 
 */
bool Board::setCoordinate(int row, int col) {
    Coordinate coordinate;
    if ((col > COLSIZE || col < 0) || row == -1) {
        return false;
    }
    coordinate.set(row,col);
    return true;
}

/**
 * @brief Takes the column and finds the next empty row
 * 
 * @param col Column selected by player
 * @return int Returns available row or -1 if no row is available
 */
int Board::findAvailableRow(int col) {
    for (int i = 0; i < ROWSIZE; ++i) {
        char symbol = board[i][col];
        if (i == ROWSIZE - 1 && symbol == 'O') {
            return i;
        } else if (symbol != 'O') { 
            return i - 1; 
        } 
    }
    return -1;
}

/**
 * @brief Determines if there are 4 tokens in a row
 * 
 * @param token Player's token
 * @return true Tokens are connected
 * @return false Tokens are not connected
 */
bool Board::isConnected(char token) {
    for (int col = 0; col <= 6; ++col) {
        for (int row = 0; row <= 2; ++row) {
            if (board[row][col] == token && board[row + 1][col] == token && board [row + 2][col] == token && board[row + 3][col] == token) {
                return true;
            }
        }
    }

    for (int col = 0; col <= 3; ++col) {
        for (int row = 0; row <= 5; ++row) {
            if (board[row][col] == token && board[row][col + 1] == token && board [row][col + 2] == token && board[row][col + 3] == token) {
                return true;
            }
        }
    }

    for (int col = 0; col <= 3; ++col) {
        for (int row = 0; row <= 2; ++row) {
            if (board[row][col] == token && board[row + 1][col + 1] == token && board [row + 2][col + 2] == token && board[row + 3][col + 3] == token) {
                return true;
            }
        }
    }

    for (int col = 0; col <= 3; ++col) {
        for (int row = 5; row >= 3; --row) {
            if (board[row][col] == token && board[row - 1][col + 1] == token && board [row - 2][col + 2] == token && board[row - 3][col + 3] == token) {
                return true;
            }
        }
    }
    return false;
}     

/**
 * @brief Keeps track of current player
 * 
 * @param token Player token
 */
void Board::setPlayer(char token) {
    currPlayer = token;
}




//------ SFML FUNCTIONS ------//

/**
 * @brief Retrieves window reference
 * 
 * @return sf::RenderWindow* 
 */
sf::RenderWindow* Board::getWindow() {
    return &window;
}

/**
 * @brief Initializes the SFML window
 * 
 */
void Board::intitalize() {
    window.create(sf::VideoMode(1080, 1010), "Connect Four");
}

/**
 * @brief Render's the SFML window with graphics
 * 
 */
void Board::render() {
    const int distance = 150; 
    const float offset = distance / 20.f; 
    const float height = std::sqrt(std::pow(distance, 2.f) - std::pow(offset, 2.f)); 

    window.clear(sf::Color(0, 76, 153, 255)); 
    window.draw(header);
    window.draw(num);

    if (currPlayer == 'R') {
        usleep(100000);
        window.draw(playerTwo);
    } else if (currPlayer == 'Y') {
        usleep(100000);
        window.draw(playerOne);
    }
     
    for (int row = 0; row < ROWSIZE; ++row) {
        for (int col = 0; col < COLSIZE; ++col) {
            if (board[row][col] == 'Y') {
                yellowToken.setPosition(col * distance + offset + 30, row * height + 130);
                window.draw(yellowToken);
            } else if (board[row][col] == 'R') {
                redToken.setPosition(col * distance + offset + 30, row * height + 130);
                window.draw(redToken);
            } else {
                emptyToken.setPosition(col * distance + offset + 30, row * height + 130);
                window.draw(emptyToken);
            }
        }
    }

    if (isConnected(currPlayer) && currPlayer == 'R') {
        window.draw(playerOneWin);
        window.display();
        sleep(10);
    } else if (isConnected(currPlayer) && currPlayer == 'Y') {
        window.draw(playerTwoWin);
        window.display();
        sleep(10);
    }
    window.display();
}