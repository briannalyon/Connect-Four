#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h> 
#include "player.h"
#include "board.h"
using std::cout;
using std::endl;

int main() {

    srand(time(0));

    bool won = false;
    int player = 1;
    int status = -1;
    Board board;
    Human playerOne(&board); 
    Computer playerTwo(&board); 

    sf::RenderWindow* window = board.getWindow();
    window->setKeyRepeatEnabled(false);
    window->display();
    board.setPlayer(playerOne.getToken());

    cout << "Welcome to Connect Four!" << endl;

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) 
                window->close();

            if (player % 2 == 1) {
                playerOne.delay();
                status = playerOne.takeTurn(event);
            } else {
                playerTwo.delay();
                status = playerTwo.takeTurn(event);
            }

            if (status == 0) {
                continue;
            } else if (status == 1) { //turn done
                player = (player + 1) % 2;
                break;
            } else if (status == 2 ) { //win 
                won = true;
                break;
            }
        }
        if (player % 2) {
            board.setPlayer(playerOne.getToken());
        } else {
            board.setPlayer(playerTwo.getToken());
        }
        board.render();
        if (won) {
            sleep(10);
            break;
        }
    }
    return 0;
}