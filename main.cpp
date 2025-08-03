#include <raylib.h>

#include "Game.h"

int main() {
    InitWindow(500,500, "Falling Sand");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        game.Draw();
        DrawFPS(400, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
