//
// Created by michal on 7/26/25.
//

#include "Board.h"

#include <iostream>

#include "Elements/Air.h"
#include "Elements/Sand.h"

Board::Board() {
    height = 25;
    width = 25;
    cellSize = 10;
    gridOffset = 10;
    Initialize(height, width);
}

void Board::Initialize(const int height, const int width) {
    for (int row = 0; row < height; row++) {
        std::vector<Cell> rowVector;

        for (int column = 0; column < width; column++) {
            Air cell;
            rowVector.push_back(cell);
        }

        cells.push_back(rowVector);
    }
}

void Board::InputToCell(const int row, const int column) {
    if (IsWithinBounds(row, column) == false) {return;}
    cells[row][column] = Sand();
}


void Board::PrintBoard() const {
    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {
            std::cout << cells[i][j].ID << " ";
        }

        std::cout << std::endl;
    }
}

void Board::DrawBoard() const {
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            const Color cellColor = cells[row][column].color;
            DrawRectangle(column*cellSize + gridOffset, row*cellSize + gridOffset, cellSize, cellSize, cellColor);
        }
    }
}

bool Board::IsWithinBounds(const int row, const int col) const {
    const int rows = cells.size();
    const int cols = cells[0].size();
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }
    return true;
}
