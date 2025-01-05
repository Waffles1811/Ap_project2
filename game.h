#ifndef AP_GAME_H
#define AP_GAME_H
#include "camera.h"
#include "include/stopwatch.h"
#include "view.h"
#include "include/world.h"
#include <fstream>
#include <map>
#include <string>
class game {
protected:
    std::unique_ptr<dj::World> world;
    std::unique_ptr<camera> theCamera;
    std::shared_ptr<view> playerView;

public:
    game();

    /*
     *
     * sets up the game and world at the start or after a reset
     *
     */
    void setUp();

    /*
     *
     * runs the main game loop
     *
     */
    void main_game_loop();

    /*
     *
     * processes inputs and calls the necessary functions in world or player
     *
     */
    void processInputs();

    /*
     *
     * shows the game over screen and then waits until r is pressed
     *
     */
    void gameOver();

    /*
     *
     * destructs everything
     *
     */
    void kill();
};

#endif // AP_GAME_H
