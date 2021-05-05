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
    int player = 1;
    const sf::Color Red = sf::Color(Red);
    const sf::Color Yellow = sf::Color(Yellow);
    Player playerOne('Y', Yellow, false, &board); 
    Player playerTwo('R', Red, false, &board); 

    cout << "Welcome to Connect Four!" << endl;
    sf::RenderWindow* window = board.getWindow();
    window->display();

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (player == 1) {
            playerOne.outputBoard();
            playerOne.move();
            won = playerOne.hasWon('Y');
            if(won) break;
            player = 2;
        } else {
            playerTwo.outputBoard();
            playerTwo.move();
            won = playerTwo.hasWon('R');
            if(won) break;
            player = 1;
        }

        board.render();
    }
    return 0;
}