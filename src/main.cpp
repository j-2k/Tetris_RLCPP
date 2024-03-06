#include <iostream>
#include <raylib.h>
#include "game.h"


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

    Game game = Game();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

 /*
    Grid grid = Grid();

    grid.grid[0][3] = 1;
    grid.grid[1][4] = 2;
    grid.grid[2][5] = 3;
    grid.grid[3][6] = 4;
    grid.grid[4][7] = 5;
    grid.grid[5][8] = 6;
    grid.grid[6][9] = 7;
 
    TBlock L_BLOCK = TBlock();
    L_BLOCK.Move(9,3);
   
    for (auto a : L_BLOCK.cells)
    {
        for (auto &e : a.second)
        {
            e.col += 5;
            e.row += 10;
            std::cout << a.first << " x:" << e.col<< " y:" << e.row << std::endl;
        }
    }

    grid.Log();
    
    //grid.Draw();
    //L_BLOCK.Draw();
    */

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();

            //DrawText("Congrats! You created your first window!", (screenWidth*0.5) - (screenWidth*0.12), screenHeight*0.5, 20, LIGHTGRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();        // Close window and OpenGL context

    return 0;
}