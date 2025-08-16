//
// Created by michal on 8/16/25.
//

#include "Clay.h"

Clay::Clay() {
    ID = 1;
    color = Color(255, 128, 0, 255);
    useGravity = true;
    isSolid = true;
    dormantTime = 3;
    friction = 2;
    ColorOffset();
}
