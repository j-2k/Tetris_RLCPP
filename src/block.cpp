#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw()
{
    std::vector<Position> tiles = cells[rotationState];
    for(Position pos : tiles)
    {
        //pos.col += 5;
        //pos.row += 10;

        DrawRectangle(pos.col * cellSize + 1,pos.row * cellSize + 2, 
        cellSize-1,cellSize-1,colors[id]);

        //std::cout << pos.col << " " << pos.row << std::endl;
    }
}
