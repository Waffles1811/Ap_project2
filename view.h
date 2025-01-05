//
// Created by jensp on 2/01/2025.
//

#ifndef AP_VIEW_H
#define AP_VIEW_H
#include "entityModel.h"
#include "factories/graphic_factory.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
class view : public cameraObserver {
public:
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Font> font;
    std::map<int, std::unique_ptr<sf::Sprite>> sprites;
    std::vector<std::unique_ptr<sf::Texture>> textures;
    spriteFactory spritesIncorperated;
    int score;

    view();

    /*
     *
     * called if a model changes, if this happens the model gets drawn
     *
     */
    void update(entityModel& model) override;

    /*
     *
     * called if a score changes
     *
     */
    void update(int _score) override;

    /*
     *
     * draws the score at the top of the screen
     *
     */
    void drawScore() const;

    /*
     *
     * draws the game over screen
     *
     */
    void drawGameOverScreen();

    /*
     *
     * calls drawscore and releaseframe at the end of a frame
     *
     */
    void endFrame() const;

    /*
     *
     * shows screen to user, then resets it for the next frame
     *
     */
    void releaseFrame() const;
};

#endif // AP_VIEW_H
