//
// Created by michal on 7/26/25.
//

#include "Sand.h"

Sand::Sand() {
    ID = 1;
    color = YELLOW;
    useGravity = true;
    isSolid = true;
    dormantTime = 500;
    friction = 10;
    ColorOffset();
}
