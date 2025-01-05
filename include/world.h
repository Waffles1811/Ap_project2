#ifndef AP_WORLD_H
#define AP_WORLD_H
#include "factories/entity_factory.h"
#include "factories/singletons.h"
#include <cmath>
namespace dj {
class World {
private:
    std::unique_ptr<rngFactory> randomNumber;
    int height;
    int lastPlatforms;
    std::vector<std::unique_ptr<platformFactory>> platformFactories;
    int difficulty;
    int score;
    int heightScore;

public:
    std::vector<std::shared_ptr<platform>> platforms;
    std::shared_ptr<player> Player;
    std::vector<std::shared_ptr<BG_tile>> BG_tiles;

    World();

    /*
     *
     * returns player
     *
     */
    std::vector<std::shared_ptr<platform>> getPlatforms();

    /*
     *
     * returns player
     *
     */
    std::shared_ptr<player> getPlayer();

    /*
     *
     * returns background tiles
     *
     */
    std::vector<std::shared_ptr<BG_tile>> getbackground();

    /*
     *
     * returns score
     *
     */
    int getScore();
    /*
     *
     * returns height
     *
     */
    [[nodiscard]] int getHeight() const;

    /*
     *
     * checks if the player landed on platform and if yes it calls the functions associated with that
     *
     */
    void landedCheck(float time);

    /*
     *
     * makes all entities time up
     *
     */
    void timeUp(float time);

    /*
     *
     * updates the world height so it can accurately destroy platforms and spawn in new ones
     *
     */
    void updateWorldHeight();

    /*
     *
     * adds new platforms every so often
     *
     */
    void makeNewPlatforms(int estimatedHeight);
};
} // namespace dj
#endif // AP_WORLD_H
