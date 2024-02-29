#include "grid.h"
#include <iostream>
//#include <raylib.h>

Grid::Grid()
{
    row = 20;
    col = 10;
    cellSize = 30;
    Start();
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

