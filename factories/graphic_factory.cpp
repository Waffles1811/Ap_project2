//
// Created by jensp on 2/01/2025.
//

#include "graphic_factory.h"
#include <iostream>

static std::shared_ptr<sf::Texture> texture = std::shared_ptr<sf::Texture>(new sf::Texture());

spriteFactory::spriteFactory() {
    playerTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!playerTexture->loadFromFile("assets/textures/player.png")) {
        throw std::runtime_error(
            "player texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }
    greenpltfTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!greenpltfTexture->loadFromFile("assets/textures/green_platform.png")) {
        throw std::runtime_error(
            "green platform texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }
    bluepltfTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!bluepltfTexture->loadFromFile("assets/textures/blue_platform.png")) {
        throw std::runtime_error(
            "blue platform texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }

    yellowpltfTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!yellowpltfTexture->loadFromFile("assets/textures/yellow_platform.png")) {
        throw std::runtime_error("yellow platform texture file failed to load.\nplease ensure this is texture is "
                                 "present in assets/textures");
    }
    whitepltfTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!whitepltfTexture->loadFromFile("assets/textures/white_platform.png")) {
        throw std::runtime_error(
            "white platform texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }
    springTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!springTexture->loadFromFile("assets/textures/spring.png")) {
        throw std::runtime_error(
            "spring texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }
    jetpackTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!jetpackTexture->loadFromFile("assets/textures/jetpack.png")) {
        throw std::runtime_error(
            "jetpack texture file failed to load.\nplease ensure this is texture is present in assets/textures");
    }
    backgroundTileTexture = std::unique_ptr<sf::Texture>(new sf::Texture());
    if (!backgroundTileTexture->loadFromFile("assets/textures/BG_tile.png")) {
        throw std::runtime_error("background tile texture file failed to load.\nplease ensure this is texture is "
                                 "present in assets/textures");
    }
}

std::unique_ptr<sf::Sprite> spriteFactory::createPlayerSprite() {
    auto sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*playerTexture));
    sprite->setScale(0.2021, 0.2021);
    return sprite;
}
std::unique_ptr<sf::Sprite> spriteFactory::createPlatformSprite(int type) {
    std::unique_ptr<sf::Sprite> sprite;
    switch (type) {
    case 1:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*greenpltfTexture));
        break;
    case 2:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*bluepltfTexture));
        break;
    case 3:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*yellowpltfTexture));
        break;
    case 4:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*whitepltfTexture));
        break;
    }
    sprite->setScale(0.12, 0.07);
    return sprite;
}

std::unique_ptr<sf::Sprite> spriteFactory::createBonusSprite(int type) {
    std::unique_ptr<sf::Sprite> sprite;
    switch (type) {
    case 1:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*springTexture));
        sprite->setScale(0.385, 0.209);
        break;
    case 2:
        sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*jetpackTexture));
        sprite->setScale(0.104, 0.104);
        break;
    }
    return sprite;
}

std::unique_ptr<sf::Sprite> spriteFactory::createBackgroundSprite() {
    std::unique_ptr<sf::Sprite> sprite = std::unique_ptr<sf::Sprite>(new sf::Sprite(*backgroundTileTexture));
    sprite->setScale(0.0366, 0.0367);
    return sprite;
}
