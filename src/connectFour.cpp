#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "player.h"
#include "board.h"
using std::cout;
using std::endl;

int main() {
    srand(time(0));
    Board board;
    bool won = false;
    cout << "Welcome to Connect Four!" << endl;
    sf::RenderWindow* window = board.getWindow();
    window->display();
        while (window->isOpen()) {	// should this be the game loop
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            Player playerOne('Y', false, &board); // X stands for a color
            playerOne.outputBoard();
            playerOne.move();
            won = playerOne.hasWon('Y');
            if(won) break;

            Player playerTwo('R', false, &board); // X stands for a color
            playerTwo.outputBoard();
            playerTwo.move();
            won = playerTwo.hasWon('R');
            if(won) break;
        }
    return 0;
}