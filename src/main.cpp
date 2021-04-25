/**
 * @file main.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include <iostream>
#include "board.h"
#include "player.h"
#include "token.h"
#include "coordinate.h"

using std::cout;

int main(int argc, char *argv[])
{
    srand (time(0));
    cout << "Welcome to Connect Four" << endl;

    Player playerOne;
    playerOne.placeToken();
    playerOne.outputBoard();

    Player playerTwo(true);
    playerTwo.placeToken();
    playerTwo.outputBoard();

	bool winner = false;

	while(!winner)
	{
        playerOne.move(&playerTwo);
        playerTwo.move(&playerOne);

        cout << "Player 1" << endl;
        playerOne.outputBoard(); // UPDATE GRAPHICS
        cout << "Player 2" << endl;
        playerTwo.outputBoard(); // UPDATE GRAPHICS

        if (playerOne.hasLost())
        {
            cout << "Player two has won the game!" << endl;
            winner = true;
        }
        else if (playerTwo.hasLost())
        {
            cout << "Player one has won the game!" << endl;
            winner = true;
        }
	}

	return 0;
}