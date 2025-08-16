#include <raylib.h>
#include "Game.h"
#include "raygui.h"
#include "GUI/gui.h"

int main() {
    InitWindow(700,500, "Falling Sand");
    SetTargetFPS(60);

    Game game;
    GuiLoadStyle("../cmake-build-debug/_deps/raygui-src/styles/dark/style_dark.rgs");
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
