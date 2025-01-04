//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_SCREENMANAGER_H
#define TEST0_SCREENMANAGER_H

#include <memory>
#include "IScreen.h"
#include "IScreenManager.h"

namespace screen {
    class ScreenManager : public IScreenManager, public std::enable_shared_from_this<ScreenManager> {
    public:
        explicit ScreenManager(std::shared_ptr<IResourceManager> resourceManager);

        void draw();

        void setNextScreen(ScreenType screen) override;

        void setStartScreen(ScreenType screen) override;

        bool shouldClose() override;

        ~ScreenManager() override = default;

    private:
        std::unique_ptr<IScreen> currentScreen;
        std::unique_ptr<IScreen> nextScreen;
        std::shared_ptr<IResourceManager> resourceManager;

        bool closeWindow = false;
        bool needInitWindow = false;
    };
}

#endif //TEST0_SCREENMANAGER_H
