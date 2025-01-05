#ifndef AP_PLAYER_H
#define AP_PLAYER_H
namespace dj {

class player {
protected:
    double x_coord;
    double y_coord;
    double y_speed;
    bool isLanded;
    bool movingLeft;
    bool movingRight;

public:
    player();
    player(double xCoord, double yCoord);

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
     * return y_speed
     *
     */
    [[nodiscard]] double getYSpeed() const;

    /*
     *
     * times up player: moves it and tells the observer it exists
     *
     */
    void time_up(float time);

    /*
     *
     * accelerates the player upwards
     *
     */
    void goUp(int acceleration);

    /*
     *
     * sets movingRight to true making it go to the right
     *
     */
    void goRight();

    /*
     *
     * sets movingLeft to true making it go to the left
     *
     */
    void goLeft();

    /*
     *
     * sets movingRight to false
     *
     */
    void stopRight();

    /*
     *
     * sets movingLeft to false
     *
     */
    void stopLeft();

    /*
     *
     * called if player landed on platform, resets the y_speed and sets isLanded to true so it can jump
     *
     */
    void landed();

    /*
     *
     * called if player leaves a platform, sets isLanded to false so it can't jump again
     *
     */
    void left();
};
} // namespace dj
#endif // AP_PLAYER_H
