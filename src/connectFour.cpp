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
    bool won = false;
    cout << "Welcome to Connect Four!" << endl;

    while (1) {
        Player playerOne('X', false, &board); // X stands for a color
        playerOne.outputBoard();
        playerOne.move();
        won = playerOne.hasWon('X');
        if(won) {break;}

        Player playerTwo('B', false, &board); // X stands for a color
        playerTwo.outputBoard();
        playerTwo.move();
        won = playerTwo.hasWon('B');
        if(won) {break;}
    }
    return 0;
}