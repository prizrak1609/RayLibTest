//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_ISCREENMANAGER_H
#define TEST0_ISCREENMANAGER_H

namespace screen {
    enum class ScreenType : int {
        LOGO,
        MENU,
        GAME,
        ENDING
    };

    class IScreenManager {
    public:
        virtual void setNextScreen(ScreenType screen) = 0;
        virtual void setStartScreen(ScreenType screen) = 0;
        virtual bool shouldClose() = 0;

        virtual ~IScreenManager() = default;
    };
}

#endif //TEST0_ISCREENMANAGER_H
