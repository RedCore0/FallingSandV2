//
// Created by michal on 7/23/25.
//

#include "Game.h"

Game::Game() {
    board = Board();
}

void Game::HandleInput() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();

        int row = (mousePosition.y - board.gridOffset) / board.cellSize;
        int column = (mousePosition.x - board.gridOffset) / board.cellSize;

        board.InputToCell(row, column);
    }
}

void Game::Draw() const {
    board.DrawBoard();
}
