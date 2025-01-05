#ifndef AP_PLATFORM_H
#define AP_PLATFORM_H
#include "bonus.h"
namespace dj {

class platform {
protected:
    double x_coord;
    double y_coord;
    bool jumpedOn;
    std::shared_ptr<bonus> platformBonus;

public:
    platform(double xCoord, double yCoord);

    ~platform();

    /*
     *
     * return x_coord
     *
     */
    [[nodiscard]] double getXCoord() const;

    /*
     *
     * return y_coord
     *
     */
    [[nodiscard]] double getYCoord() const;

    /*
     *
     * returns offsets, if it doesn't have an offset is should return 0
     *
     * return 0
     *
     */
    [[nodiscard]] virtual double getOffset() const;

    /*
     *
     * returns jumpedOn variable
     *
     */
    [[nodiscard]] virtual bool getjumpedOn() const;

    /*
     *
     * returns the bonus item
     *
     */
    [[nodiscard]] virtual std::shared_ptr<bonus> getBoost() const;

    /*
     *
     * sets the bonus to a shared pointer to a bonus, otherwise it's a nullpt
     *
     */
    void setBonus(std::shared_ptr<bonus> _bonus);

    /*
     *
     * if this platform has a bonus, this function will trigger that bonus
     * sets jumpedOn to true and tells observer to subtract points from the score if the player already landed on this
     *
     */
    void landed(int playerXCoord);

    /*
     *
     * moves the platform to these new coordindates
     *
     */
    void move(int newX, int newY);

    /*
     *
     * times up the function, tells the observer it exists
     *
     */

    virtual void time_up(float time);

    /*
     *
     * checks if the platform and bonus is still on the screen
     *
     * return: true if on screen, false if not
     *
     */

    [[nodiscard]] virtual bool checkOnScreen(int height) const;

    /*
     *
     * pure virtual function to make inheriting classes return their type
     *
     */

    [[nodiscard]] virtual int getType() const = 0;
};

class static_pf : public platform {
public:
    static_pf(double xCoord, double yCoord);

    /*
     *
     * return: its type: 1
     *
     */
    [[nodiscard]] int getType() const override;
};

class horizontal_pf : public platform {
private:
    double speed;
    double offset;

public:
    horizontal_pf(double xCoord, double yCoord);

    /*
     *
     * return: offset
     *
     */
    double getOffset() const override;

    /*
     *
     * moves the platform nd tells the observer it exists
     *
     */
    void time_up(float time) override;

    /*
     *
     * return: its type: 2
     *
     */
    [[nodiscard]] int getType() const override;
};

class vertical_pf : public platform {
private:
    int speed;
    double offset;

public:
    vertical_pf(double xCoord, double yCoord);

    /*
     *
     * return: offset
     *
     */
    double getOffset() const override;

    /*
     *
     * moves the platform and tells the observer it exists
     *
     */
    void time_up(float time) override;

    /*
     *
     * overrides function so the heighest point it will be has to be below the screen
     *
     * return: true if it is above the screen or can come back onto the screen, false if not
     *
     */
    [[nodiscard]] bool checkOnScreen(int height) const override;

    /*
     *
     * return: its type: 3
     *
     */
    [[nodiscard]] int getType() const override;
};
class temp_pf : public platform {
public:
    temp_pf(double xCoord, double yCoord);

    /*
     *
     * return: its type: 4
     *
     */
    [[nodiscard]] int getType() const override;
};
} // namespace dj
#endif // AP_PLATFORM_H
