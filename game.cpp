#include "game.h"
game::game() : playerView(std::make_shared<view>(view())), theCamera(std::unique_ptr<camera>(new camera())) {
    theCamera->setUp(playerView);
}

void game::setUp() { world = std::unique_ptr<dj::World>(new dj::World()); }

void game::main_game_loop() {
    setUp();
    dj::stopwatchFactory stopwatchInc;
    float timeSinceLastTic;
    stopwatchInc.getStopwatch()->timeTic(); // called here so it isn't too long later
    while (playerView->window->isOpen()) {
        if (world->Player->getYCoord() < world->getHeight()) { // game over is the player goes below the screen
            gameOver();                                        // sits in this function untill r is pressed
            world.reset();                                     // resets world
            setUp();                                           // sets up world
            timeSinceLastTic = stopwatchInc.getStopwatch()->timeTic();
            // ^ resets the time so doesn't count the whole time the game over screen was up
        }

        timeSinceLastTic = stopwatchInc.getStopwatch()->timeTic(); // gets time since last tic

        processInputs(); // processes inputs

        world->timeUp(timeSinceLastTic); // world calculates what happened since last frame

        theCamera->update(*world);

        playerView->endFrame(); // shows frame to the player
    }
}

void game::processInputs() {
    sf::Event event;
    while (playerView->window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            // if a key being pressed adds speed it will be added every tic which will make the player very fast,
            // instead it sets a variable to true which moves the player
            if (event.key.code == sf::Keyboard::Left or event.key.code == sf::Keyboard::A) {
                // ^ maybe change this back to scancode on windows, didn't work on linux for me
                world->Player->goLeft();
            } else if (event.key.code == sf::Keyboard::Right or event.key.code == sf::Keyboard::D) {
                world->Player->goRight();
            }
            break;
        case sf::Event::KeyReleased:
            // sets the variable to false again if the key isn't being pressed anymore
            if (event.key.code == sf::Keyboard::Left or event.key.code == sf::Keyboard::A) {
                world->Player->stopLeft();
            } else if (event.key.code == sf::Keyboard::Right or event.key.code == sf::Keyboard::D) {
                world->Player->stopRight();
            }
            break;
        case sf::Event::Closed:
            playerView->window->close(); // also exits program
            this->kill();
            return;
        }
    }
}

void game::gameOver() {
    playerView
        ->drawGameOverScreen(); // draws the game over screen which stays on screen for the duration of this function
    while (playerView->window->isOpen()) {
        sf::Event event;
        while (playerView->window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code ==
                    sf::Keyboard::R) { // maybe change this back to scancode on windows, didn't work on linux for me
                    setUp();
                    playerView->sprites[0]->setScale(0.2021, 0.2021); // sets the player sprite to normal
                    return;
                }
                break;

            case sf::Event::Closed:
                playerView->window->close(); // also exits program
                this->kill();
                return;
            }
        }
    }
}

void game::kill() {
    // TODO: delete everything :)
}