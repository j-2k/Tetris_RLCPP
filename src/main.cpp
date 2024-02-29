#include <raylib.h>
#include "grid.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 301;
    const int screenHeight = 602;

    InitWindow(screenWidth, screenHeight, "Raylib Core Basic Window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //My Additions
    Grid grid = Grid();

    grid.grid[0][0] = 1;
    grid.grid[1][1] = 2;
    grid.grid[2][2] = 3;
    grid.grid[3][3] = 4;
    grid.grid[4][4] = 5;
    grid.grid[5][5] = 6;
    grid.grid[6][6] = 7;

    grid.Log();

    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            grid.Draw();

            //DrawText("Congrats! You created your first window!", (screenWidth*0.5) - (screenWidth*0.12), screenHeight*0.5, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}