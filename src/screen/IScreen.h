//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_ISCREEN_H
#define TEST0_ISCREEN_H

#include <memory>
#include "IScreenManager.h"
#include "IResourceManager.h"

namespace screen {
    class IScreen {
    public:
        virtual void init(std::weak_ptr<IResourceManager> resourceManager, std::weak_ptr<IScreenManager> screenManager) = 0;

        virtual void update() = 0;

        virtual void draw() = 0;

        virtual void unload() = 0;

        virtual bool shouldClose() = 0;

        virtual ~IScreen() = default;
    };
}

#endif //TEST0_ISCREEN_H
