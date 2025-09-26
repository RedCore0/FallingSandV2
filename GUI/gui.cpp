//
// Created by michal on 8/10/25.
//
#define RAYGUI_IMPLEMENTATION
#include "gui.h"

#include <raygui.h>

gui::gui() {
    selectedElement = 0;
}

void gui::Draw() {
    GuiToggleGroup((Rectangle){505, 20, 190, 40}, "Sand\nDirt\nClay\nStone", &selectedElement);
}
