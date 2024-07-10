#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(800, 600, "Raylib Test");

    // Main game loop (runs until the window should close)
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Raylib is working!", 190, 200, 20, RED);
        EndDrawing();
    }

    // De-initialize the window
    CloseWindow();

    return 0;
}