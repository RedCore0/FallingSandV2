//
// Created by michal on 8/10/25.
//

#include "Dirt.h"

Dirt::Dirt() {
    ID = 1;
    color = BROWN;
    useGravity = true;
    isSolid = true;
    dormantTime = 10;
    friction = 5;
    ColorOffset();
}
