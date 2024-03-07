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

bool Grid::isCellOutOfBounds(int r, int c)
{
    if(r >= 0 && r < rows && c >= 0 && c < cols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int r, int c)
{
    if(grid[r][c] == 0)
    {
        return true;
    }
    return false;
}

bool Grid::isRowCompleted (int r)
{
    for (int column = 0; column < cols; column++)
    {
        if(grid[r][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int r)
{
    for (int column = 0; column < cols; column++)
    {
        grid[r][column] = 0;
    }
}

void Grid::MoveRowDown(int r, int downOffset)
{
    for (int column = 0; column < cols; column++)
    {
        grid[r + downOffset][column] = grid[r][column];
        grid[r][column] = 0;
    }
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int r = rows - 1; r >= 0; r --)
    {
        if(isRowCompleted(r))
        {
            ClearRow(r);
            completed++;
            
        }
        else if (completed > 0)
        {
            MoveRowDown(r,completed);
        }
    }
    return completed;
}