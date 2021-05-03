#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
using std::cout;
using std::endl;

int main() {
    srand(time(0));
    cout << "Welcome to Connect Four!" << endl;

    Player playerOne('X', false); // X stands for a color
    playerOne.outputBoard();
    playerOne.move();
    return 0;
}