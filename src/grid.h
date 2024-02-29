#pragma once

class Grid{
    public:
        Grid();
        void Start();
        void Log();
        int grid[20][10];

    private:
        int row;        //20
        int col;        //10
        int cellSize;   //30

};