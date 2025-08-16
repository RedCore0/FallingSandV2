//
// Created by michal on 7/23/25.
//

#ifndef GAME_H
#define GAME_H
#include "Board/Board.h"
#include "GUI/gui.h"


class Game {
public:
    Game();
    void HandleInput();
    void Update();
    void Draw();
private:
    Board board;
    gui gameGui;
};



#endif //GAME_H
