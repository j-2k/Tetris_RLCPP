#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randIndex = rand() % blocks.size();
    Block block = blocks[randIndex];
    blocks.erase(blocks.begin() + randIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::InputHandler()
{
    int keyPressed = GetKeyPressed();

    switch(keyPressed)
    {
        case KEY_LEFT:
        MoveBlockLeft();
        break;

        case KEY_RIGHT:
        MoveBlockRight();
        break;

        case KEY_DOWN:
        MoveBlockDown();
        break;

        case KEY_UP:
        RotateBlock();
        break;

    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0,-1);
    if(isBlockOutside())
    {
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0,1);
    if(isBlockOutside())
    {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1,0);
    if(isBlockOutside() || !BlockFits())
    {
        currentBlock.Move(-1,0);
        Locked();
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position p : tiles)
    {
        if(grid.isCellOutOfBounds(p.row,p.col))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if(isBlockOutside())
    {
        currentBlock.UndoRotation();
    }
}

void Game::Locked()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position p : tiles)
    {
        grid.grid[p.row][p.col] = currentBlock.id;
    }

    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position p : tiles)
    {
        if(grid.isCellEmpty(p.row,p.col) == false)
        {
            return false;
        }
    }
    return true;
    
}