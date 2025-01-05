//
// Created by jensp on 30/12/2024.
//

#ifndef AP_BONUS_H
#define AP_BONUS_H
#include "player.h"
#include <memory>
namespace dj {
class bonus {
public:
    int x_coord_offset;
    std::shared_ptr<player> thePlayer;
    bonus(int xCoord, std::shared_ptr<player> _player);

    /*
     *
     * return: x_coord_offset
     *
     */
    [[nodiscard]] int getXOffset() const;

    /*
     *
     * pure virtual function which makes all inheriting classes have an activate bonus
     *
     */
    virtual void activateBonus() = 0;

    /*
     *
     * times up this item, does nothing except notify the observer in this case
     *
     */
    virtual void time_up(float time);

    /*
     *
     * pure virtual function which makes inheriting classes return their type number
     *
     */
    [[nodiscard]] virtual int getType() const = 0;

    /*
     *
     * returns if it is working, here always false
     *
     * return: false
     *
     */
    virtual bool isWorking();
};

class spring : public bonus {
public:
    spring(int xCoord, std::shared_ptr<player> _player);
    ~spring();
    /*
     *
     * activates the bonus, making the player jump 5 times as high
     *
     */
    void activateBonus() override;

    /*
     *
     * return: its type: 5
     *
     */
    [[nodiscard]] int getType() const override;
};

class jetpack : public bonus {
private:
    float remainingFuelTime;

public:
    jetpack(int xCoord, std::shared_ptr<player> _player);
    ~jetpack();

    /*
     *
     * activates the bonus: it launches the player at a consistent speed for 3 seconds
     *
     */
    void activateBonus() override;

    /*
     *
     * lowers the time left that this item will keep boosting the player
     *
     */
    void time_up(float time) override;

    /*
     *
     * return: its type : 6
     *
     */
    [[nodiscard]] int getType() const override;

    /*
     *
     * return: true while it's boosting the player, otherwise false
     *
     */
    [[nodiscard]] bool isWorking() override;
};
} // namespace dj
#endif // AP_BONUS_H
