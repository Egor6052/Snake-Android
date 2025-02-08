#pragma once

#include <vector>
#include <raylib.h>
#include "Food.h"


struct SnakeSegment {
    int row;
    int col;
};

class Snake : public Food {

    private:
        Texture2D headTexture;
        Texture2D bodyTexture;
        Texture2D tailTexture;

        Texture2D tail2Texture;


        int numRows;
        int numCols;

        int snakeRow, snakeCol;

        std::size_t snakeSize;
        int dirRow, dirCol;
        
        std::vector<SnakeSegment> body;
        int calories;
        int growthThreshold; 

        float money;

    public:
        Snake();
        ~Snake();
        bool SnakeIsDead;

        void setMoney(int valueMoney);
        int getMoney();

        void snakeGrowth();

        void SnakeDraw();
        void SnakeClear();

        void UpdateSnake();

        void CrashedIntoSnake(int valueRow, int valueCol);
        void Reset();
        

        void SnakeEatFood();
        int getCalories();
        
        // void FoodGeneration();
};
