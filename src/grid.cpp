#include "grid.h"
#include <iostream>
//#include <raylib.h>
#include "colors.h"

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