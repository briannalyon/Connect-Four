/**
 * @file ConnectFour.cpp
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "player.h"
#include "token.h"
//#include "coordinate.h"

using std::cout;
using std::endl;

int main()
{
    //srand (time(0));
    cout << "Welcome to Connect Four" << endl;

    // Player playerOne;
    // playerOne.outputBoard();
    // playerOne.placeToken();

    // Player playerTwo(true); // Computer Playing
    // playerTwo.outputBoard(); // Output updatedboard
    // playerTwo.placeToken();

	// bool winner = false;

	// while(!winner)
	// {
    //     playerOne.move(&playerTwo);
    //     playerTwo.move(&playerOne);

    //     cout << "Player 1" << endl;
    //     playerOne.outputBoard(); // UPDATE GRAPHICS
    //     cout << "Player 2" << endl;
    //     playerTwo.outputBoard(); // UPDATE GRAPHICS

    //     if (playerOne.hasLost())
    //     {
    //         cout << "Player two has won the game!" << endl;
    //         winner = true;
    //     }
    //     else if (playerTwo.hasLost())
    //     {
    //         cout << "Player one has won the game!" << endl;
    //         winner = true;
    //     }
	// }

	return 0;
}