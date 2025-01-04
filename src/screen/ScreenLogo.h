//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_SCREENLOGO_H
#define TEST0_SCREENLOGO_H

#include "IScreen.h"

namespace screen {
    class ScreenLogo : public IScreen {
    public:
        void init(std::weak_ptr<IResourceManager> resourceManager, std::weak_ptr<IScreenManager> screenManager) override;

        void update() override;

        void draw() override;

        void unload() override;

        bool shouldClose() override;

        virtual ~ScreenLogo() = default;

    private:
        int framesCounter = 0;
        bool finishScreen = false;

        int logoPositionX = 0;
        int logoPositionY = 0;

        int lettersCount = 0;

        int topSideRecWidth = 0;
        int leftSideRecHeight = 0;

        int bottomSideRecWidth = 0;
        int rightSideRecHeight = 0;

        int state = 0;
        float alpha = 1.0f;

        std::weak_ptr<IScreenManager> screenManager;
        std::weak_ptr<IResourceManager> resourceManager;
    };
}

#endif //TEST0_SCREENLOGO_H
