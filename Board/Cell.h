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
    bool useGravity;
    bool isSolid;
    bool isActive;

    int timeToDormant;
    int dormantTime;

    int verticalVelocity;
    int horizontalVelocity;
    int horizontalVelocityTravelled;
    int horizontalDir;
    int acceleration;

    void ColorOffset();
    void UpdatePosition(int X, int Y);
    int RandomInRange(int min, int max);
    int posX;
    int posY;
};



#endif //CELL_H
