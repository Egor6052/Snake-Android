#include <iostream>
#include <random>
#include "../../lib/Food.h"

Food::Food() {
    this->foodRow = 0;
    this->foodCol = 0;

    // Завантажуємо текстури у вектор
    std::vector<std::string> texturePaths = {
        "assets/Apple.png",
        "assets/money.png",
        "assets/cherry.png",
        "assets/cookie.png"
    };

    for (const std::string& path : texturePaths) {
        Texture2D tex = LoadTexture(path.c_str());
        
        // Перевіряємо, чи завантажилася текстура
        if (tex.id == 0) {
            std::cerr << "Error: Failed to load texture: " << path << std::endl;
        } else {
            foodTextures.push_back(tex);
        }
    }

    // Перевіряємо, чи є завантажені текстури
    if (!foodTextures.empty()) {
        selectedFoodTexture = &foodTextures[0];
    } else {
        selectedFoodTexture = nullptr;
        std::cerr << "Error: No food textures loaded!" << std::endl;
    }
}

Food::~Food() {
    for (auto& texture : foodTextures) {
        UnloadTexture(texture);
    }
}

// Генеруємо нову їжу
void Food::FoodGeneration() {

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> randTexture(0, foodTextures.size() - 1);
    selectedFoodTexture = &foodTextures[randTexture(generator)];

    std::uniform_int_distribution<int> rowDistribution(0, getNumRows() - 1);
    std::uniform_int_distribution<int> colDistribution(0, getNumCols() - 1);

    int randomRow, randomCol;
    do {
        randomRow = rowDistribution(generator);
        randomCol = colDistribution(generator);
    } while (grid[randomRow][randomCol] == 7);

    this->foodRow = randomRow;
    this->foodCol = randomCol;

}

// Малюємо їжу
void Food::DrawFood() {
    if (selectedFoodTexture) {
        DrawTexture(*selectedFoodTexture, foodCol * 30, foodRow * 30, WHITE);
    } else {
        std::cout << "Error: selectedFoodTexture is nullptr!\n";
    }
}


int Food::getFoodRow(){
    return this->foodRow;
}
int Food::getFoodCol(){
    return this->foodCol;
}

// void Food::SnakeEatFood(int colorFood){
//     FoodGeneration();
//     if (colorFood == 1){
//         calories++;
//     } else if (colorFood == 2){
//         calories += 2;
//     } else if (colorFood == 3){
//         calories += 3;
//     } else if (colorFood == 4){
//         calories += 4;
//     } else if (colorFood == 5){
//         calories += 1;
//     } else if (colorFood == 6){
//         calories += 1;
//     } else if (colorFood == 7){
//         calories += 1;
//     } else if (colorFood == 8){
//         calories += 1;
//     }
// }
