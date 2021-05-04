#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "board.h"
using std::cout;
using std::endl;

int main() {
    srand(time(0));
    Board board;
    cout << "Welcome to Connect Four!" << endl;

    Player playerOne('X', false, &board); // X stands for a color
    playerOne.outputBoard();
    playerOne.move();

    Player playerTwo('B', false, &board); // X stands for a color
    playerTwo.outputBoard();
    playerTwo.move();

    playerOne.outputBoard();
    playerOne.move();
    
    return 0;
}