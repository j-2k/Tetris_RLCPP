#pragma once

#include "blocksall.cpp"
#include "grid.h"

class Game{
    public:
        Game();
        Game(int sX, int sY);
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();

        void InputHandler();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

        bool isGameOver;

        int totalScore;

    private:
        void InitializeGame();
        bool isBlockOutside();
        void RotateBlock();
        void Locked();
        bool BlockFits();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

        int screenX;
        int screenY;

        void Reset();

};