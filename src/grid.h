#pragma once
#include <vector>
#include <raylib.h>
#include "colors.h"

class Grid{
    public:
        Grid();

        void Start();
        void Log();

        void Draw();
        int grid[20][10];

        bool isCellOutOfBounds(int row, int col);
        bool isCellEmpty(int row, int col);

        int ClearFullRows();

    private:
        bool isRowCompleted(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int downOffset);
        int rows;        //20
        int cols;        //10
        int cellSize;   //30
        std::vector<Color> colors;

};