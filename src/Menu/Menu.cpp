#include <raylib.h>
#include <iostream>
#include <string>
#include <thread>

#include "../../lib/Menu.h"

Menu::Menu() {
    screenWidth = 800.0f;
    screenHeight = 600.0f;

    isInMenu = true;
    isPaused = false;

    this->Massage = "";
}

Menu::~Menu() {}

void Menu::ResetGame() {
    snake.Reset();
    setMessage("");
    isPaused = false;
}

// Функція для відображення екрану меню
void Menu::ShowMenu() {
    Color buttonColor = { 100, 100, 255, 255 };
    Color buttonHoverColor = { 120, 120, 255, 255 };

    Vector2 buttonPosition = { static_cast<float>(screenWidth / 2) - 200.0f, static_cast<float>(screenHeight / 2) - 30.0f };
    Vector2 buttonSize = { 200.0f, 50.0f };

    if (getMessage() != "") {
        DrawText((getMessage() + "\n\nYour score: " + std::to_string(snake.getMoney())).c_str(), (int)(screenWidth - 570), (int)(screenHeight - 430), 20, LIGHTGRAY);
    }

    // Кнопка для початку гри
    if (CheckCollisionPointRec(GetMousePosition(), { buttonPosition.x, buttonPosition.y, buttonSize.x, buttonSize.y })) {
        buttonColor = buttonHoverColor;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            ResetGame(); // Скидаємо гру перед початком
            isInMenu = false;
            Start();
        }
    }
    DrawRectangle(static_cast<int>(buttonPosition.x), static_cast<int>(buttonPosition.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), buttonColor);
    DrawText("Start Game", static_cast<int>(buttonPosition.x) + 50, static_cast<int>(buttonPosition.y) + 15, 20, LIGHTGRAY);


    // Кнопка для виходу
    buttonPosition.y += 60;
    if (CheckCollisionPointRec(GetMousePosition(), {buttonPosition.x, buttonPosition.y, buttonSize.x, buttonSize.y })) {
        buttonColor = buttonHoverColor;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Exit();
        }
    }
    DrawRectangle(static_cast<int>(buttonPosition.x), static_cast<int>(buttonPosition.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), buttonColor);
    DrawText("Exit", static_cast<int>(buttonPosition.x) + 85, static_cast<int>(buttonPosition.y) + 15, 20, LIGHTGRAY);
}

void Menu::Start() {
    isInMenu = false;

    // Якщо гра на паузі, відображаємо повідомлення про паузу і кнопку "Продовжити"
    if (isPaused) {
        DrawText("Game Paused", (int)(screenWidth / 2) - 220, (int)(screenHeight / 2) - 50, 40, LIGHTGRAY);

        // Кнопка для продовження гри
        Color buttonColor = { 100, 100, 255, 255 };
        Color buttonHoverColor = { 120, 120, 255, 255 };
        Vector2 buttonPosition = { (float)(screenWidth / 2 - 200), (float)(screenHeight / 2 + 30) };
        Vector2 buttonSize = { 200.0f, 50.0f };

        if (CheckCollisionPointRec(GetMousePosition(), { buttonPosition.x, buttonPosition.y, buttonSize.x, buttonSize.y })) {
            buttonColor = buttonHoverColor;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                Pause();  // Продовжити гру (скасувати паузу)
            }
        }

        DrawRectangle(static_cast<int>(buttonPosition.x), static_cast<int>(buttonPosition.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), buttonColor);
        DrawText("Continue", static_cast<int>(buttonPosition.x) + 50, static_cast<int>(buttonPosition.y) + 15, 20, LIGHTGRAY);

        return;  // Не оновлюємо змію, поки гра на паузі
    }

    // Кнопка для паузи
    Color buttonColor = { 100, 100, 255, 255 };
    Color buttonHoverColor = { 120, 120, 255, 255 };
    Vector2 buttonPosition = { (float)(screenWidth / 2 + 20), (float)(screenHeight -10) }; // Оновлене розташування кнопки
    Vector2 buttonSize = { 150.0f, 40.0f };

    if (CheckCollisionPointRec(GetMousePosition(), { buttonPosition.x, buttonPosition.y, buttonSize.x, buttonSize.y })) {
        buttonColor = buttonHoverColor;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Pause();
        }
    }

    DrawRectangle(static_cast<int>(buttonPosition.x), static_cast<int>(buttonPosition.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), buttonColor);
    DrawText("Pause", static_cast<int>(buttonPosition.x) + 10, static_cast<int>(buttonPosition.y) + 10, 20, LIGHTGRAY);

    // Оновлюємо змію і її малювання
    snake.UpdateSnake();
    snake.SnakeDraw();

    // Перевірка на смерть змії
    if (snake.SnakeIsDead) {
        setMessage("Game Over!");
        isInMenu = true;
    }
    else {
        DrawText(("Your score: " + std::to_string(snake.getMoney())).c_str(), 40, screenHeight + 10, 20, LIGHTGRAY);
    }
    // Затримка після малювання всіх сегментів
    std::this_thread::sleep_for(std::chrono::milliseconds(95));
}

void Menu::setMessage(std::string valueMessage) {
    this->Massage = valueMessage;
}

std::string Menu::getMessage() {
    return this->Massage;
}

void Menu::Pause() {
    isPaused = !isPaused;
}

void Menu::Exit() {
    CloseWindow();
}
