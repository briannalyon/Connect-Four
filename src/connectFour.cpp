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
    int col = -1;
    Player playerOne('Y', false, &board); 
    Player playerTwo('R', false, &board); 

    cout << "Welcome to Connect Four!" << endl;
    sf::RenderWindow* window = board.getWindow();
    window->setKeyRepeatEnabled(false);
    window->display();
    board.setPlayer('Y');
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) 
                window->close();
            if (event.type == sf::Event::KeyPressed) 
            {
                col = -1;
                if (event.key.code == sf::Keyboard::Num1) col = 1;
                else if (event.key.code == sf::Keyboard::Num2) col = 2;
                else if (event.key.code == sf::Keyboard::Num3) col = 3;
                else if (event.key.code == sf::Keyboard::Num4) col = 4;
                else if (event.key.code == sf::Keyboard::Num5) col = 5;
                else if (event.key.code == sf::Keyboard::Num6) col = 6;
                else if (event.key.code == sf::Keyboard::Num7) col = 7;

                cout << col;

                if (col != -1) {
                    if (player == 1) {
                        
                        playerOne.outputBoard();
                        playerOne.move(col);
                        won = playerOne.hasWon('Y');
                        if (won) break;
                        board.setPlayer('R');
                        player = 2;
                    } else {
                        
                        playerTwo.outputBoard();
                        playerTwo.move(col);
                        won = playerTwo.hasWon('R');
                        if (won) break;
                        board.setPlayer('Y');
                        player = 1;
                    }
                }
            }
        }
        board.render();
        if (won) break;
            // FIX: SFML TEXT (CURRENT PLAYER W/COLOR, WINNER)
            // TODO: PRESENTATION OUTLINE
            // TODO: COME UP WITH PRESENTATION QUESTIONS FOR OTHER TEAMS
            //what was the hardest part to complete in your project?
            
            // NOTE: ASK ABOUT INHERITENCE AND POLYMORPHISM
            
            //Inheritance is appropriate when
            // objects of the new class are a subset of the objects of the existing class, or 
            // objects of the new class will be used in the same ways as the objects of the existing class

            // Polymorphic code: Code that behaves differently when it acts on objects of different types
            
        
    }
    return 0;
}