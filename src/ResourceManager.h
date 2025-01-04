//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_RESOURCEMANAGER_H
#define TEST0_RESOURCEMANAGER_H

#include "IResourceManager.h"

class ResourceManager: public IResourceManager {
public:
    void loadResources() override;

    void unloadResources() override;

    ~ResourceManager() override = default;
};

#endif //TEST0_RESOURCEMANAGER_H
