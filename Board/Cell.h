//
// Created by michal on 7/26/25.
//

#ifndef CELL_H
#define CELL_H
#include "raylib.h"


class Cell {
public:
    Cell();
    int ID;
    Color color{};

    void ColorOffset();
    int RandomInRange(int min, int max);
};



#endif //CELL_H
