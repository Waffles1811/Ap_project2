#ifndef AP_ENTITY_FACTORY_H
#define AP_ENTITY_FACTORY_H
#include "../BG_tile.h"
#include "../platform.h"
#include "singletons.h"
#include <string>
#include <vector>

namespace dj {
class platformFactory {
public:
    /*
     * makes a platform
     *
     * return: a unique pointer to the platform
     */
    virtual std::shared_ptr<platform> createPlatform(int estheight,
                                                     std::vector<std::shared_ptr<dj::platform>> platforms,
                                                     rngFactory& randomNumber, std::shared_ptr<player> Player) = 0;
    void addBonus(std::shared_ptr<platform> newPlatform, rngFactory& randomNumber, std::shared_ptr<player> Player);
    std::pair<int, int> calcCoordinates(int estheight, int type, std::vector<std::shared_ptr<platform>> platforms,
                                        rngFactory& randomNumber);
};

class playerFactory {
public:
    /*
     * makes a player
     *
     * return: a shared pointer to the player
     */
    virtual std::shared_ptr<player> createPlayer();
};

class bonusItemFactory {
public:
    /*
     * makes a bonus item
     *
     * return: a shared pointer to the item
     */
    virtual std::shared_ptr<bonus> createBonusItem(int x_coord, std::shared_ptr<player> player) = 0;
};

class staticPlatformFactory : public platformFactory {
public:
    /*
     *
     * makes a static platform
     *
     */
    std::shared_ptr<platform> createPlatform(int estheight, std::vector<std::shared_ptr<platform>> platforms,
                                             rngFactory& randomNumber, std::shared_ptr<player> Player) override;
};

class horizontalPlatformFactory : public platformFactory {
public:
    /*
     *
     * makes a horizontal platform
     *
     */
    std::shared_ptr<platform> createPlatform(int estheight, std::vector<std::shared_ptr<platform>> platforms,
                                             rngFactory& randomNumber, std::shared_ptr<player> Player) override;
};

class verticalPlatformFactory : public platformFactory {
public:
    /*
     *
     * makes a vertical platform
     *
     */
    std::shared_ptr<platform> createPlatform(int estheight, std::vector<std::shared_ptr<platform>> platforms,
                                             rngFactory& randomNumber, std::shared_ptr<player> Player) override;
};

class temporaryPlatformFactory : public platformFactory {
public:
    /*
     *
     * makes a temporary platform
     *
     */
    std::shared_ptr<platform> createPlatform(int estheight, std::vector<std::shared_ptr<platform>> platforms,
                                             rngFactory& randomNumber, std::shared_ptr<player> Player) override;
};

class startLocationPlayerFactory : playerFactory {
public:
    /*
     * makes a platform in the start location (200, 0)
     *
     * return: a shared pointer to the player
     */
    std::shared_ptr<player> createPlayer() override;
};

class springFactory : public bonusItemFactory {
public:
    /*
     * makes a spring
     *
     * return: a shared pointer to the spring
     */
    std::shared_ptr<bonus> createBonusItem(int x_coord, std::shared_ptr<player> player) override;
};

class jetpackFactory : public bonusItemFactory {
public:
    /*
     * makes a jetpack
     *
     * return: a shared pointer to the jetpack
     */
    std::shared_ptr<bonus> createBonusItem(int x_coord, std::shared_ptr<player> player) override;
};

class backgroundFactory {
public:
    /*
     * makes a background tile
     *
     * return: a shared pointer to the background tile
     */
    virtual std::shared_ptr<BG_tile> createBackgroundTile(int x_coord, int y_coord);
};
} // namespace dj

#endif // AP_ENTITY_FACTORY_H
