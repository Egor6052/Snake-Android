#include <iostream>
#include <random>
#include "../../lib/Background.h"

Background::Background(){
    this->numRows = 20;
    this->numCols = 20;
    this->cellSize = 30;
    Initialize();

    colors = GetCellColors();
}
Background::~Background(){}

int Background::getNumRows(){
    return this->numRows;
}

int Background::getNumCols(){
    return this->numCols;
}


void Background::Print(){
    for (int row = 0; row < numRows; row ++){
        for (int column = 0; column < numCols; column++){
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;

    }
}

void Background::Initialize(){
    for (int row = 0; row < numRows; row ++){
        
        for (int column = 0; column < numCols; column ++){
            grid[row][column] = 6;
        }
    }
    // Snake::FoodGeneration();
}

std::vector<Color> Background::GetCellColors() {
    Color green = {34, 139, 34, 255};   //0
    Color red = {220, 20, 60, 255};     //1
    Color orange = {255, 140, 0, 255};  //2
    Color purple = {128, 0, 128, 255};  //3
    Color cyan = {0, 255, 255, 255};    //4
    Color blue = {0, 0, 255, 255};      //5
    Color darkGray = {26, 31, 40, 255}; //6
    Color yellow = {255, 255, 0, 255};  //7


    return {green, red, orange, purple, cyan, blue, darkGray, yellow};
}

void Background::Draw(){
    for (int row = 0; row < numRows; row ++){
        for (int column = 0; column < numCols; column ++){
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize -1, colors[cellValue]);
        }
    }
}


// void Background::Draw(){
//     for (int row = 0; row < numRows; row ++){
//         for (int column = 0; column < numCols; column ++){
//             int cellValue = grid[row][column];
//             // DrawRectangle(x, y, w, h, color);
//             DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize -1, colors[cellValue]);
//         }
//     }
// }