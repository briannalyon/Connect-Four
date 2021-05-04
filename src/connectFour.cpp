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

    while (1) {

        while (window->isOpen()) {	// should this be the game loop
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
            }
            board.render();
            window->display();
        }

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