#pragma once
#include <vector>
#include <raylib.h>

class Background {
    private:
        int numRows;
        int numCols;
        int cellSize;

        // int grid[20][40];
        std::vector<Color> GetCellColors();
        std::vector<Color> colors;

    public:
        int grid[20][20];
        Background();
        ~Background();

        int getNumRows();
        int getNumCols();

        void Initialize();
        void Print();

        void Draw();
};