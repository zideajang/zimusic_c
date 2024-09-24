#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include <time.h>
#include <unistd.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "sound loading and playing");
    InitAudioDevice();
    // Sound  fxOgg = LoadSound("example.ogg");
    Music  music = LoadMusicStream("example.ogg");
    PlayMusicStream(music);


    SetTargetFPS(60);   

    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        // if (IsKeyPressed(KEY_SPACE)) PlaySound(fxOgg); 
        BeginDrawing();

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}