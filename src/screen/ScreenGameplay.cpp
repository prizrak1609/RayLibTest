//
// Created by gubat on 17.01.2025.
//

#include "ScreenGameplay.h"
#include "raylib.h"
#include <string>

void screen::ScreenGameplay::init(std::weak_ptr<IResourceManager> resourceManager,
                                  std::weak_ptr<IScreenManager> screenManager) {
    this->resourceManager = resourceManager;
    this->screenManager = screenManager;

    framesCounter = 0;
}

void screen::ScreenGameplay::update() {
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        shouldCloseScreen = true;
        Sound coin = resourceManager.lock()->getSound("fxCoin");
        PlaySound(coin);
    }
}

void screen::ScreenGameplay::draw() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    Vector2 pos = { 20, 10 };
    Font font = resourceManager.lock()->getFont("font");
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
}

void screen::ScreenGameplay::unload() {
}

bool screen::ScreenGameplay::shouldClose() {
    return shouldCloseScreen;
}
