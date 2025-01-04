//
// Created by gubat on 04.01.2025.
//

#include "ScreenMenu.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>

using namespace screen;

void ScreenMenu::init(std::weak_ptr<IResourceManager> resourceManager, std::weak_ptr<IScreenManager> screenManager) {
    this->resourceManager = resourceManager;
    this->screenManager = screenManager;

    startGameButton = { 20, 40, 150, 40 };

    screenManager.lock()->setNextScreen(ScreenType::GAME);
}

void ScreenMenu::update() {
    startGameButton.y = getButtonY();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), startGameButton)) {
        shouldCloseScreen = true;
    }
}

float ScreenMenu::getButtonY() {
    if (buttonMoveDown) {
        clampButton += GetFrameTime() / 2;
    } else {
        clampButton -= GetFrameTime() / 2;
    }

    if (clampButton >= 1.f) {
        buttonMoveDown = false;
    } else if (clampButton <= 0.f) {
        buttonMoveDown = true;
    }
    return Lerp(40, 40 + 3, clampButton);
}

void ScreenMenu::draw() {
    DrawRectangleRec(startGameButton, BLUE);
    DrawText("Start Game", startGameButton.x + 10.f, startGameButton.y + 10.f, 20, WHITE);
}

void ScreenMenu::unload() {
}

bool ScreenMenu::shouldClose() {
    return shouldCloseScreen;
}
