//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_SCREENMENU_H
#define TEST0_SCREENMENU_H

#include "IScreen.h"
#include "raylib.h"

namespace screen {
    class ScreenMenu : public IScreen {
    public:
        void init(std::weak_ptr<IResourceManager> resourceManager, std::weak_ptr<IScreenManager> screenManager) override;

        void update() override;

        void draw() override;

        void unload() override;

        bool shouldClose() override;

        ~ScreenMenu() override = default;

    private:
        Rectangle startGameButton;
        bool shouldCloseScreen = false;
        std::weak_ptr<IScreenManager> screenManager;
        std::weak_ptr<IResourceManager> resourceManager;

        bool buttonMoveDown = true;
        float clampButton = 0.f;
        float getButtonY();
    };
}

#endif //TEST0_SCREENMENU_H
