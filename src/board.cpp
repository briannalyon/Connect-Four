    #include "board.h"

    Board::Board() {
        for (int row = 0; row < ROWSIZE; ++row) {
            for (int col = 0; col < COLSIZE; ++col) {
                board[row][col] = 'O';
            }
        }
    }

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

        if (!inBounds(coordinate) || !isClear(coordinate)) {
            return false;
        }
        board[row][col - 1] = token;
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
        ((col > COLSIZE || col < 1) || (row > ROWSIZE || row < 1)) ? check = false : check = true;
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
        if ((col > COLSIZE || col < 1) || row == -1) {
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