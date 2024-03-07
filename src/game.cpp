#include "game.h"
#include <string>
#include <random>

Game::Game()
{
    InitializeGame();
}

Game::Game(int sX, int sY)
{
    InitializeGame();

    screenX = sX;
    screenY = sY;
}

void Game::InitializeGame()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    isGameOver = false;
    totalScore = 0;
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

    //this is trash but idrc just doing it fast idc abt optimization rn
    if(isGameOver){
        DrawRectangle((screenX*0.5) - (screenX*0.49), screenY*0.5,screenX,screenY*0.25,BLACK);
        DrawText("GAMEOVER!", (screenX*0.5) - (screenX*0.49), screenY*0.5, 50, WHITE);
        DrawText("Press any key to restart!", (screenX*0.5) - (screenX*0.49), screenY*0.6, 22, WHITE);
        
        std::string s = "Score: " + std::to_string(totalScore);
        char const *pchar = s.c_str(); 
        DrawText(pchar, (screenX*0.5) - (screenX*0.3), screenY*0.7, 22, WHITE);
    }
}

void Game::InputHandler()
{
    int keyPressed = GetKeyPressed();

    if(isGameOver && keyPressed != 0)
    {
        isGameOver = false;
        Reset();
    }

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
    if(isGameOver){return;}

    currentBlock.Move(0,-1);
    if(isBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight()
{
    if(isGameOver){return;}

    currentBlock.Move(0,1);
    if(isBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown()
{
    if(isGameOver){return;}

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
    if(isBlockOutside() ||!BlockFits())
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

    //gameover
    if(!BlockFits())
    {
        isGameOver = true;
    }

    nextBlock = GetRandomBlock();
    totalScore += grid.ClearFullRows();
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

void Game::Reset()
{
    grid.Start();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}