//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_IRESOURCEMANAGER_H
#define TEST0_IRESOURCEMANAGER_H

class IResourceManager {
public:
    virtual ~IResourceManager() = default;

    virtual void loadResources() = 0;
    virtual void unloadResources() = 0;
};

#endif //TEST0_IRESOURCEMANAGER_H
