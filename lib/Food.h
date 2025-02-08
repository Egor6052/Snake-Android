#pragma once

#include <vector>
#include <raylib.h>
#include "Background.h"

class Food : public Background {
    private:
        int foodRow;
        int foodCol;

        std::vector<Texture2D> foodTextures;
        Texture2D* selectedFoodTexture;
    public:

        Food();
        ~Food();

        int getFoodRow();
        int getFoodCol();

        // float getCalories();
        void FoodGeneration();
        void DrawFood();
};
