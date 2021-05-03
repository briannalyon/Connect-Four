    #include "board.h"

    Board::Board() {
        for (int row = 0; row < ROWSIZE; ++row) {
            for (int col = 0; col < COLSIZE; ++col) {
                board[row][col] = 'O';
            }
        }
    }

    void Board::display() {
        cout << " 1 2 3 4 5 6 7" << endl;
        for (int row = 0; row < ROWSIZE; ++row) {
            for (int col = 0; col < COLSIZE; ++col) {
                cout << board[row][col] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    bool Board::placeToken(Coordinate coordinate, char token) {
        int row = coordinate.getRow();
        int col = coordinate.getCol();

        if (!inBounds(coordinate) || !isClear(coordinate)) {
            return false;
        }
        board[row][col] = token;
        return true;
    }

    bool Board::isClear(Coordinate coordinate) {
        int row = coordinate.getRow();
        int col = coordinate.getCol();

        if (board[row][col] != 'O') {
            return false;
        }
        return true;
    }

    bool Board::inBounds(Coordinate coordinate) {
        if (coordinate.getCol() > COLSIZE || coordinate.getRow() > ROWSIZE) {
            // check for less than 1
            return false;
        }
        return true;
    }

    void Board::updateBoard(Coordinate coordinate, char token) {
        int row = coordinate.getRow();
        int col = coordinate.getCol();
        board[row][col] = token;
    }

    // char Board::getTokenColor(Coordinate coordinate) {

    // }

    void Board::randomizeCoordinate() {
        Coordinate coordinate;
        int col = 1 + rand() % 10;
        coordinate.set(col, findAvailableRow(col));
    }

    bool Board::setCoordinate(int row, int col) {
        Coordinate coordinate;
        if (!(col < COLSIZE && col > 0) && row != -1) {
            return false;
        }
        coordinate.set(row,col);
        return true;
    }

    int Board::findAvailableRow(int col) {
        for (int i = 0; i < COLSIZE; ++i) {
            char symbol = board[i][col];
            if (symbol != 'O') { return i - 1; }
        }
        return -1; // No row available in column
    }

    bool Board::isConnected() {
        return false;
    }     