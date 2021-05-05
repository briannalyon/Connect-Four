#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
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
    int col = 0;
    Player playerOne('Y', false, &board); 
    Player playerTwo('R', false, &board); 

    cout << "Welcome to Connect Four!" << endl;
    sf::RenderWindow* window = board.getWindow();
    window->display();

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    col = 1;
                    cout << "here" << endl;
                }
                else if (event.key.code == sf::Keyboard::Num2) col = 2;
                else if (event.key.code == sf::Keyboard::Num3) col = 3;
                else if (event.key.code == sf::Keyboard::Num4) col = 4;
                else if (event.key.code == sf::Keyboard::Num5) col = 5;
                else if (event.key.code == sf::Keyboard::Num6) col = 6;
                else if (event.key.code == sf::Keyboard::Num7) col = 7;
            }

            // FIX: GETTING KEY INPUT 
            // FIX: SFML TEXT (COLUMN NUMBERS, CURRENT PLAYER W/COLOR, WINNER)
            // TODO: PRESENTATION OUTLINE
            // TODO: COME UP WITH PRESENTATION QUESTIONS FOR OTHER TEAMS
            // NOTE: ASK ABOUT INHERITENCE AND POLYMORPHISM

                
            if (player == 1) {
                playerOne.outputBoard();
                playerOne.move(col);
                won = playerOne.hasWon('Y');
                if(won) break;
                player = 2;
            } else {
                playerTwo.outputBoard();
                playerTwo.move(col);
                won = playerTwo.hasWon('R');
                if(won) break;
                player = 1;
            }
        }
        board.render();
    }
    return 0;
}