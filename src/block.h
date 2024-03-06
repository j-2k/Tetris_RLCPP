#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
//#include <iostream>

class Block{

    public:
        Block();
        int id;
        std::map<int, std::vector<Position> > cells;
        
        void Draw();
        void Move(int rows, int cols);
        std::vector<Position> GetCellPositions();

    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;

        int rowOffset;
        int colOffset;

};