#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <fmt/core.h>

int main(int argc, char** argv)
{
    if (argc < 1) {
        fmt::println("No file provided");
        exit(1);
    }

    char* filename = argv[1];
    // std::cout << filename << std::endl;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::cout << code << std::endl;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "scratch_cpp project - basic window");

    Font roboto_font = LoadFont("assets/fonts/Roboto/Roboto-Regular.ttf");

    if (!IsFontReady(roboto_font)) {
        std::cerr << "Failed to load font\n" << std::endl;
    }

    MaximizeWindow();
    
    Texture2D nikee_256 = LoadTexture("assets/images/nikee_256.png");


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            
            DrawTextEx(roboto_font, "v0.1.0a - 25.10.24", Vector2((float)(GetScreenWidth() - 130), (float)(GetScreenHeight() - 20)), 20.0f, 0.0f, BLACK);
            
            // DrawTextureEx(nikee_256, Vector2((float)(GetScreenWidth() / 2 - 256 / 2), (float)(GetScreenHeight() / 2 - 256 / 2)), 0.0f, 1.0f, WHITE);

            DrawTextEx(roboto_font, "Hello World!", Vector2((float)(GetScreenWidth() / 2 - 256 / 2), (float)(GetScreenHeight() / 2 - 256 / 2)), 40.0f, 0.0f, BLACK);

            // DrawFPS(GetScreenWidth() - 85, 0);
        EndDrawing();
    }

    UnloadFont(roboto_font);
    CloseWindow();

    return 0;
}