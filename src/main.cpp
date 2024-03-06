#include <iostream>
#include <raylib.h>
#include "game.h"



//custom delta timer /tickrate
double lastUpdatedTimeFrame = 0;

//number inserted will return 0 or 1 depending on the time passed in as input to real time
//Basically Time.time unity
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdatedTimeFrame >= interval)
    {
        lastUpdatedTimeFrame = currentTime;
        return true;
    }
    return false;
}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Start function / initialization
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

    // update function / Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //update
        game.InputHandler();

        if(EventTriggered(0.3)) //every 3 ms drop down 1
        {
            game.MoveBlockDown();
        }

        //render
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