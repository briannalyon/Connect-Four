    #include "board.h"

    Board::Board() {
        for (int row = 0; row < ROWSIZE; ++row) {
            for (int col = 0; col < COLSIZE; ++col) {
                board[row][col] = 'O';
            }
        }
        intitalize();
        render();
    }

    sf::RenderWindow* Board::getWindow() {
        return &window;
    }

    void Board::intitalize() {
        window.create(sf::VideoMode(1080, 910), "Connect Four");
    }

    void Board::render() {
        const int nofRows = 6; //number of rows
        const int nofCols = 7; //number of columns
        const int distance = 150; //distance between tokens
        const float offset = distance / 20.f; 
        const float height = std::sqrt(std::pow(distance, 2.f) - std::pow(offset, 2.f)); 
        const sf::Color blue = sf::Color(0, 76, 153, 255);
        const sf::Color grey = sf::Color(200, 200, 200, 255);

        sf::CircleShape token(50.f);
        token.setFillColor(grey);

        window.clear(blue);
		for (int i = 0; i < nofRows; ++i) {
			for (int j = 0; j < nofCols; ++j) {
			    token.setPosition(j * distance + offset + 30, i * height + 30); //odd rows
				window.draw(token);
			}
        }
    }

    // Call board render instead of display for SFML
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

    bool Board::placeToken(Coordinate coordinate, char token) {
        int row = coordinate.row;
        int col = coordinate.col;
        cout << "PT ROW: " << row << "  COL: " << col << endl;

        if (!inBounds(coordinate) || !isClear(coordinate)) {
            return false;
        }
        board[row][col] = token;
        return true;
    }

    bool Board::isClear(Coordinate coordinate) {
        int row = coordinate.row;
        int col = coordinate.col;
        bool check;
        (board[row][col] != 'O') ? check = false : check = true;
        return check;
    }

    bool Board::inBounds(Coordinate coordinate) {
        int row = coordinate.row;
        int col = coordinate.col;
        bool check;
        ((col > COLSIZE - 1 || col < 0) || (row > ROWSIZE - 1 || row < 0)) ? check = false : check = true;
        return check;
    }

    void Board::updateBoard(Coordinate coordinate, char token) {
        int row = coordinate.row;
        int col = coordinate.col;
        board[row][col] = token;
    }

    // char Board::getTokenColor(Coordinate coordinate) {

    // }

    Coordinate Board::randomizeCoordinate() {
        Coordinate coordinate;
        int col = 1 + rand() % 10;
        coordinate.set(col, findAvailableRow(col));
        return coordinate;
    }

    bool Board::setCoordinate(int row, int col) {
        Coordinate coordinate;
        if ((col > COLSIZE || col < 0) || row == -1) {
            return false;
        }
        coordinate.set(row,col);
        return true;
    }

    int Board::findAvailableRow(int col) {
        for (int i = 0; i < ROWSIZE; ++i) {
            char symbol = board[i][col];
            cout << "Row = " << i << "  Col = " << col << "  Sym = " << symbol << endl;
            if (i == ROWSIZE - 1 && symbol == 'O') {
                return i;
            } else if (symbol != 'O') { 
                return i - 1; 
            } 
            
        }
        return -1; // No row available in column
    }

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