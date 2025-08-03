//
// Created by michal on 7/23/25.
//

#ifndef GAME_H
#define GAME_H
#include "Board/Board.h"


class Game {
public:
    Game();
    void HandleInput();
    void Update();
    void Draw() const;
private:
    Board board;
};



#endif //GAME_H
