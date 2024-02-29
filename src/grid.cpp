#include "grid.h"
#include <iostream>
//#include <raylib.h>

Grid::Grid()
{
    rows = 20;
    cols = 10;
    cellSize = 30;
    Start();
    colors = GetCellColors();
}

void Grid::Start()
{
    for(auto &a : grid)
    {
        for (int &b : a)
        {
            //b = GetRandomValue(0,9);
            b = 0;
        }
    }
}

void Grid::Log()
{
    for(const auto &a : grid)
    {
        for (int b : a)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<Color> Grid::GetCellColors()
{
    Color grey = {30,30,30,255};
    Color green = {30,255,30,255};
    Color red = {255,30,30,255};
    Color orange = {255,150,30,255};
    Color yellow = {255,255,30,255};
    Color purple = {200,30,255,255};
    Color cyan = {30,255,255,255};
    Color blue = {30,30,255,255};
    
    return {grey,green,red,orange,yellow,purple,cyan,blue};
}

void Grid::Draw()
{
    for (int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            int cellValueIndex = grid[r][c];
            DrawRectangle(c * cellSize +1, r * cellSize +2,
            cellSize-1,cellSize-1, colors[cellValueIndex]);
        }
    }
}