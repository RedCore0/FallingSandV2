//
// Created by michal on 7/26/25.
//

#ifndef BOARD_H
#define BOARD_H
#include <vector>

#include "Cell.h"

using namespace std;

class Board {
public:
    Board();

    void Initialize(int height, int width);

    void PrintBoard() const;

    void InputToCell(int row, int column, int element);

    void UpdateBoard();

    void UpdateCells();

    void DrawBoard() const;

    vector<vector<Cell>> cells;
    vector<vector<Cell>> cellsClone;
    int cellSize;
    int gridOffset;

private:
    bool setCellState;
    bool IsWithinBounds(int row, int col) const;

    void FallDown(int row, int col);

    void HorizontalFriction(int row, int col);

    bool FloorExists(int row, int col);
    bool IsActive(int row, int col);
    int RandomDirection();
    int height;
    int width;
};



#endif //BOARD_H
