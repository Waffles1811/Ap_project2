//
// Created by jensp on 2/01/2025.
//

#include "entityModel.h"

int entityModel::getXCoord() const { return x_coord; }
int entityModel::getYCoord() const { return y_coord; }
int entityModel::getType() const { return type; }
entityModel::entityModel(int xCoord, int yCoord, int _type, std::shared_ptr<cameraObserver> _observer)
    : x_coord(xCoord), y_coord(yCoord), type(_type), observer(_observer) {}
void entityModel::update(int x, int y) {
    x_coord = x;
    y_coord = y;
    observer->update(*this);
}
