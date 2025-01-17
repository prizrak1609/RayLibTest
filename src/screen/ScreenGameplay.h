//
// Created by gubat on 17.01.2025.
//

#ifndef TEST0_SCREENGAMEPLAY_H
#define TEST0_SCREENGAMEPLAY_H

#include "IScreen.h"

namespace screen {
    class ScreenGameplay: public IScreen {
    public:
        void
        init(std::weak_ptr<IResourceManager> resourceManager, std::weak_ptr<IScreenManager> screenManager) override;

        void update() override;

        void draw() override;

        void unload() override;

        bool shouldClose() override;

    private:
        std::weak_ptr<IScreenManager> screenManager;
        std::weak_ptr<IResourceManager> resourceManager;
        int framesCounter = 0;
        bool shouldCloseScreen = false;
    };
}


#endif //TEST0_SCREENGAMEPLAY_H
