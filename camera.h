//
// Created by jensp on 2/01/2025.
//

#ifndef AP_CAMERA_H
#define AP_CAMERA_H
#include "entityModel.h"
#include "view.h"
#include "include/world.h"
#include <map>
class camera {
private:
    std::map<int, std::unique_ptr<entityModel>> models;
    int height;
    std::shared_ptr<view> playerView;

public:
    camera();

    void setUp(std::shared_ptr<view> _playerView);

    /*
     *
     * makes the model if something triggered the observer
     *
     */
    void update(dj::World& world);
};

#endif // AP_CAMERA_H
