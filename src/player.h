/**
 * @file player.h
 * @author Josie Wicklund and Brianna Lyon
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"
#include "coordinate.h"

class Player
{
    public:
            Player();
            Player(bool);
            void manuallyPlaceToken(int token);
            void randomlyPlaceToken(int token);
            //bool isAutomaticPlacement();
            int getPlacementCol(int col);
            void placeToken();
            void outputBoard();
            Coordinate getCoordinate();
            bool registerMove();
            //Coordinate coordinate);
            void move(Player *opponent);
            bool hasLost();
            bool registerMove(Coordinate coordinate);
    private:
        Board board;
        bool isComputer;
};

#endif