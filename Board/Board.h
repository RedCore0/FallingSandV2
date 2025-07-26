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

    void InputToCell(int row, int column);

    void DrawBoard() const;

    vector<vector<Cell>> cells;
    int cellSize;
    int gridOffset;

private:
    int height;
    int width;

    bool IsWithinBounds(int row, int col) const;
};



#endif //BOARD_H
