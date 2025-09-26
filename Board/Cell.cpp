//
// Created by michal on 7/26/25.
//

#include "Cell.h"

#include <cstdlib>
#include <random>

Cell::Cell() {
    ID = 0;
    color = BLUE;
    useGravity = false;
    isSolid = false;
    isActive = true;
    verticalVelocity = 0;
    verticalVelocityTravelled = 0;
    horizontalVelocity = 0;
    horizontalVelocityTravelled = 0;
    horizontalDir = 0;
    acceleration = 0;
    posX = 0, posY = 0;
    dormantTime = 0;
    timeToDormant = 0;
    friction = 0;
}

void Cell::ColorOffset() {
    float brightnessFactor = -0.2f + ((float)rand() / (float)RAND_MAX)* 0.2f;
    color = ColorBrightness(color, brightnessFactor);
}

void Cell::UpdatePosition(int X, int Y) {
    if (X == posX || Y == posY) {timeToDormant++;}
    if (X != posX || Y != posY) {timeToDormant = 0;}
    if (timeToDormant >= dormantTime) {isActive = false;}
    posX = X;
    posY = Y;
}

int Cell::RandomInRange(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
