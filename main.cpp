#include <raylib.h>

#include "Game.h"

int main() {
    InitWindow(500,500, "Falling Sand");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
        //hello
    }

    CloseWindow();
    return 0;
}
