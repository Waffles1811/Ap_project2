//
// Created by jensp on 2/01/2025.
//

#ifndef AP_GRAPHIC_FACTORY_H
#define AP_GRAPHIC_FACTORY_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>

class spriteFactory {
protected:
    std::unique_ptr<sf::Texture> playerTexture;
    std::shared_ptr<sf::Texture> greenpltfTexture;
    std::shared_ptr<sf::Texture> bluepltfTexture;
    std::shared_ptr<sf::Texture> yellowpltfTexture;
    std::shared_ptr<sf::Texture> whitepltfTexture;
    std::shared_ptr<sf::Texture> springTexture;
    std::shared_ptr<sf::Texture> jetpackTexture;
    std::shared_ptr<sf::Texture> backgroundTileTexture;

public:
    /*
     * the initializer, also reads the .png files
     *
     * return: nothing
     */
    spriteFactory();
    /*
     * makes a sprite
     *
     * return: a unique pointer to the sprite
     */
    virtual std::unique_ptr<sf::Sprite> createPlayerSprite();
    virtual std::unique_ptr<sf::Sprite> createPlatformSprite(int type);
    virtual std::unique_ptr<sf::Sprite> createBonusSprite(int type);
    virtual std::unique_ptr<sf::Sprite> createBackgroundSprite();
};

#endif // AP_GRAPHIC_FACTORY_H
