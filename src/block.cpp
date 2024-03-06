#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();//cells[rotationState];
    for(Position pos : tiles)
    {
        //pos.col += 5;
        //pos.row += 10;

        DrawRectangle(pos.col * cellSize + 1,pos.row * cellSize + 2, 
        cellSize-1,cellSize-1,colors[id]);

        //std::cout << pos.col << " " << pos.row << std::endl;
    }
}

void Block::Move(int rows, int cols)
{
    rowOffset += rows;
    colOffset += cols;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.col + colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if(rotationState == -1)
    {
        rotationState = cells.size()-1;
    }
}