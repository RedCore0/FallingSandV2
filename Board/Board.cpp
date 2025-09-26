//
// Created by michal on 7/26/25.
//

#include "Board.h"

#include <iostream>
#include <random>

#include "Elements/Air.h"
#include "Elements/Clay.h"
#include "Elements/Dirt.h"
#include "Elements/Sand.h"
#include "Elements/Stone.h"

Board::Board() {
    height = 250;
    width = 250;
    cellSize = 2;
    gridOffset = 0;
    setCellState = true;
    Initialize(height, width);
}

void Board::Initialize(const int height, const int width) {
    for (int row = 0; row < height; row++) {
        std::vector<Cell> rowVector;

        for (int column = 0; column < width; column++) {
            Air cell;
            cell.posX = row;
            cell.posY = column;
            rowVector.push_back(cell);
        }

        cells.push_back(rowVector);
    }
}

void Board::InputToCell(const int row, const int column, int element) {
    if (IsWithinBounds(row, column) == false) {return;}
    Cell CellToInput;
    switch (element) {
        case 0:
            CellToInput = Sand();
            break;
        case 1:
            CellToInput = Dirt();
            break;
        case 2:
            CellToInput = Clay();
            break;
        case 3:
            CellToInput = Stone();
            break;
        default:
            break;
    }
    cells[row][column] = CellToInput;
    cells[row+1][column] = CellToInput;
    cells[row-1][column] = CellToInput;
    cells[row][column+1] = CellToInput;
    cells[row][column-1] = CellToInput;
}

void Board::UpdateBoard() {
    cellsClone = cells;
    for (int row = width-1; row >= 0; row--) {
        for (int column = height-1; column>=0; column--) {
            setCellState = true;
            if (cellsClone[row][column].isActive == false){continue;}

            if (cellsClone[row][column].useGravity) {
                FallDown(row, column);
            }

            if (cellsClone[row][column].horizontalVelocity>1) {
                HorizontalFriction(row, column);
            }
        }
    }
    UpdateCells();
    cells = cellsClone;
}

void Board::UpdateCells() {
    for (int row = 0; row < width-1; row++) {
        for (int column = 0; column < height-1; column++) {
            cellsClone[row][column].UpdatePosition(row, column);
        }
    }
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

void Board::FallDown(int row, int col) {
    if (row+2 > height) {return;}
    if (FloorExists(row, col)){return;}
    Cell thisCell = cellsClone[row][col];
    if (cellsClone[row+1][col].isSolid) {
        int dir = RandomDirection();
        if (col < width-1 && col > 0 && cellsClone[row+1][col+dir].isSolid == false) {
            std::swap(cellsClone[row][col], cellsClone[row+1][col+dir]);
        }
    }else {

        if (thisCell.acceleration < 10) {
            thisCell.acceleration++;
        }

        if (thisCell.acceleration == 10) {
            if (thisCell.verticalVelocity < 10){ thisCell.verticalVelocity++;}
            thisCell.acceleration = 0;
        }

        if (row+thisCell.verticalVelocity > height-1) {
            thisCell.horizontalVelocity = thisCell.verticalVelocity*thisCell.friction;
            thisCell.verticalVelocity = 1;
        }
        if (cellsClone[row+thisCell.verticalVelocity][col].isSolid == true) {
            thisCell.horizontalVelocity = thisCell.verticalVelocity*thisCell.friction;
            thisCell.verticalVelocity = 1;
        }

        cellsClone[row][col] = cellsClone[row+thisCell.verticalVelocity][col];
        cellsClone[row+thisCell.verticalVelocity][col] = thisCell;
    }


}

void Board::HorizontalFriction(int row, int col) {

    Cell thisCell = cellsClone[row][col];
    if (thisCell.horizontalVelocityTravelled < thisCell.horizontalVelocity) {
        if (thisCell.horizontalDir == 0){thisCell.horizontalDir = RandomDirection();}
        if (cellsClone[row][col+thisCell.horizontalDir].isSolid == false) {
            cellsClone[row][col].horizontalVelocityTravelled++;
            std::swap(cellsClone[row][col], cellsClone[row][col+thisCell.horizontalDir]);
        }else {
            thisCell.horizontalVelocity = 0;
            thisCell.horizontalVelocityTravelled = 0;
            thisCell.horizontalDir = 0;
        }
    }else {
        thisCell.horizontalVelocity = 0;
        thisCell.horizontalVelocityTravelled = 0;
        thisCell.horizontalDir = 0;
    }
}

bool Board::FloorExists(int row, int col) {
    if (row+1 <= height) {return false;}

    if (cellsClone[row+1][col].isSolid == true &&
        cellsClone[row+1][col+1].isSolid == true &&
        cellsClone[row+1][col-1].isSolid == true) {
        return true;
    }
    return false;
}

int Board::RandomDirection() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 1);

    return dist(gen) == 0 ? -1 : 1;
}


