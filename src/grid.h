#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
        Grid();

        void Start();
        void Log();

        void Draw();
        int grid[20][10];

    private:
        int rows;        //20
        int cols;        //10
        int cellSize;   //30
        std::vector<Color> GetCellColors();
        std::vector<Color> colors;

};