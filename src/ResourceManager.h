//
// Created by gubat on 04.01.2025.
//

#ifndef TEST0_RESOURCEMANAGER_H
#define TEST0_RESOURCEMANAGER_H

#include <string>
#include <map>
#include "IResourceManager.h"

class ResourceManager: public IResourceManager {
public:
    void loadResources() override;

    void unloadResources() override;

    Sound getSound(const std::string &name) override;

    Font getFont(const std::string &name) override;

    ~ResourceManager() override = default;

private:
    std::map<std::string, Sound> sounds;
    std::map<std::string, Font> fonts;
};

#endif //TEST0_RESOURCEMANAGER_H
