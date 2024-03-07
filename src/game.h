#pragma once

#include "blocksall.cpp"
#include "grid.h"

class Game{
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();

        void InputHandler();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

        bool isGameOver;

    private:
        bool isBlockOutside();
        void RotateBlock();
        void Locked();
        bool BlockFits();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;

        void Reset();

};