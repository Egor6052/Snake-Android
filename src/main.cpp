#include <iostream>
#include <raylib.h>
#include "../lib/Menu.h"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "˚｡⋆Snake⋆｡˚");
    SetTargetFPS(60);
    Color backgroundColor = {40, 50, 65, 255};

    Menu game;
    //game.ShowMenu();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        if (game.isInMenu) {
            game.ShowMenu();
        } else {
            ClearBackground(backgroundColor);
            game.Start();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
