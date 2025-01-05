//
// Created by jensp on 2/01/2025.
//

#ifndef AP_ENTITYMODEL_H
#define AP_ENTITYMODEL_H
#include <memory>
class entityModel;

class cameraObserver {
public:
    virtual void update(entityModel& model) = 0;
    virtual void update(int _score) = 0;
};

class entityModel {
private:
    int x_coord;
    int y_coord;
    int type;
    std::shared_ptr<cameraObserver> observer;

public:
    entityModel(int xCoord, int yCoord, int type, std::shared_ptr<cameraObserver> _observer);

    /*
     *
     * moves the model to the new coordinates and notifies the observer
     *
     */
    void update(int x, int y);

    /*
     *
     * return: x_coord
     *
     */
    [[nodiscard]] int getXCoord() const;

    /*
     *
     * return: y_coord
     *
     */
    [[nodiscard]] int getYCoord() const;

    /*
     *
     * return: the type
     *
     */
    [[nodiscard]] int getType() const;
};

#endif // AP_ENTITYMODEL_H
