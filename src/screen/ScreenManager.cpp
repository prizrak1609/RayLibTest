//
// Created by gubat on 04.01.2025.
//

#include "ScreenManager.h"
#include "raylib.h"
#include <memory>
#include "ScreenLogo.h"
#include "ScreenMenu.h"

using namespace screen;

ScreenManager::ScreenManager(std::shared_ptr<IResourceManager> resourceManager) {
    this->resourceManager = resourceManager;
}

void ScreenManager::draw() {
//    UpdateMusicStream(music);

    if (!closeWindow) {
        if(currentScreen->shouldClose()) {
            currentScreen->unload();

            nextScreen->init(resourceManager, shared_from_this());

            if(nextScreen) {
                currentScreen.swap(nextScreen);

                nextScreen.reset();
            } else {
                closeWindow = true;
            }
        }

        if (!closeWindow) {
            currentScreen->update();
        }
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    currentScreen->draw();

    DrawFPS(10, 10);

    EndDrawing();
}

void ScreenManager::setNextScreen(ScreenType screen) {
    switch (screen) {
        case ScreenType::LOGO:
            nextScreen = std::make_unique<ScreenLogo>();
            break;
        case ScreenType::MENU:
            nextScreen = std::make_unique<ScreenMenu>();
            break;
    }
}

bool ScreenManager::shouldClose() {
    return closeWindow;
}

void ScreenManager::setStartScreen(ScreenType screen) {
    switch (screen) {
        case ScreenType::LOGO:
            currentScreen = std::make_unique<ScreenLogo>();
            break;
        case ScreenType::MENU:
            currentScreen = std::make_unique<ScreenMenu>();
            break;
    }

    currentScreen->init(resourceManager, shared_from_this());
}
