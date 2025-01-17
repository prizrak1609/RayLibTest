//
// Created by gubat on 04.01.2025.
//

#include "ResourceManager.h"

void ResourceManager::loadResources() {
    sounds["fxCoin"] = LoadSound("resources/coin.wav");

    fonts["font"] = LoadFont("resources/mecha.png");
}

void ResourceManager::unloadResources() {
    UnloadSound(sounds["fxCoin"]);

    UnloadFont(fonts["font"]);
}

Sound ResourceManager::getSound(const std::string &name) {
    return sounds[name];
}

Font ResourceManager::getFont(const std::string &name) {
    return fonts[name];
}
