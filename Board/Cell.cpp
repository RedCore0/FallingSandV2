//
// Created by michal on 7/26/25.
//

#include "Cell.h"

#include <cstdlib>
#include <random>

Cell::Cell() {
    ID = 0;
    color = BLUE;
}

void Cell::ColorOffset() {
    float brightnessFactor = -0.2f + ((float)rand() / (float)RAND_MAX)* 0.2f;
    color = ColorBrightness(color, brightnessFactor);
}

int Cell::RandomInRange(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}