//
// Created by jensp on 2/01/2025.
//

#include "camera.h"
using namespace dj;

camera::camera() : height(0) {}

void camera::setUp(std::shared_ptr<view> _playerView) {
    playerView = _playerView;
    for (int i = 0; i < 8; i++) {
        models[i] = std::unique_ptr<entityModel>(new entityModel(0, 0, i, playerView));
    }
}

void camera::update(World& world) {
    height = world.getHeight();
    std::vector<std::shared_ptr<platform>> platforms = world.getPlatforms();
    std::shared_ptr<player> Player = world.getPlayer();
    std::vector<std::shared_ptr<BG_tile>> BG_tiles = world.getbackground();
    for (auto i : BG_tiles) {
        models[7]->update(i->getXCoord(), 900 - (i->getYCoord() - height));
    }
    for (auto i : platforms) {
        models[i->getType()]->update(i->getXCoord(), 900 - (i->getYCoord() - height));
        if (i->getBoost()) {
            models[i->getBoost()->getType()]->update(i->getXCoord() + i->getBoost()->getXOffset(),
                                                     900 - (i->getYCoord() - height + 50));
        }
    }
    models[0]->update(Player->getXCoord(), 900 - (Player->getYCoord() - height));
    playerView->update(world.getScore());
}

