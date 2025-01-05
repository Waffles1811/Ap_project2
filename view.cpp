//
// Created by jensp on 2/01/2025.
//

#include "view.h"
view::view()
    : window(std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(700, 900), "doodle jump"))),
      font(std::unique_ptr<sf::Font>(new sf::Font())) {
    window->setVerticalSyncEnabled(false);
    // spriteFactory
    try {
        spritesIncorperated = spriteFactory();
        sprites[0] = spritesIncorperated.createPlayerSprite(); // this needs to be changed
        sprites[1] = spritesIncorperated.createPlatformSprite(1);
        sprites[2] = spritesIncorperated.createPlatformSprite(2);
        sprites[3] = spritesIncorperated.createPlatformSprite(3);
        sprites[4] = spritesIncorperated.createPlatformSprite(4);
        sprites[5] = spritesIncorperated.createBonusSprite(1);
        sprites[6] = spritesIncorperated.createBonusSprite(2);
        sprites[7] = spritesIncorperated.createBackgroundSprite();

        if (!font->loadFromFile("assets/font.ttf")) { // loads the font
            throw std::runtime_error("font file failed to load.\nplease ensure this is texture is present in assets");
        }
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void view::update(entityModel& model) {
    sprites[model.getType()]->setPosition(model.getXCoord(), model.getYCoord());
    window->draw(*sprites[model.getType()]);
}

void view::update(int _score) { score=_score; }


void view::endFrame() const {
    drawScore();
    releaseFrame();
}

void view::releaseFrame() const {
    window->display(); // ends frame
    window->clear();   // clears window for next frame
}

void view::drawScore() const {
    std::string Score = "score:";                               // string
    sf::Text text(Score, *font);                                // text
    text.setFillColor(sf::Color::Black);                        // text colour set to black
    text.setPosition(350 - text.getLocalBounds().width / 2, 0); // text position is centered on the screen
    window->draw(text);                                         // draws the text
    Score = std::to_string(score);
    text.setString(Score);
    text.setPosition(350 - text.getLocalBounds().width / 2, 30);
    window->draw(text);
}

void view::drawGameOverScreen() {
    std::fstream highscoreFile;
    highscoreFile.open("highscore.txt");
    std::string highscoreString;
    std::getline(highscoreFile, highscoreString); // reads the highscor file, should only be one line
    highscoreFile.close();
    if (highscoreString.size() == 0) { // if highscore file doesn't exist the string will be "" so it is set to "0"
        highscoreString = "0";
    }
    int highscore = stoi(highscoreString);
    std::string scoreOutputString = "Game Over";                 // string for text
    sf::Text text(scoreOutputString, *font);                     // makes text
    text.setFillColor(sf::Color::White);                         // sets text colour to white
    text.setPosition(350 - text.getLocalBounds().width / 2, 20); // text is centered in the middle of the screen
    window->draw(text);                                          // draws the text
    if (highscore < score) { // if a new high score is achieved the old one won't be displayed
        std::ofstream highscoreUpdate("highscore.txt");
        highscoreUpdate << score;
        highscoreUpdate.close();

        scoreOutputString = "new highscore:";
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 60);
        window->draw(text);
        scoreOutputString = std::to_string(score);
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 100);
        window->draw(text);
        scoreOutputString = "press [R] to restart";
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 140);
        window->draw(text);
    } else { // if no new highscore is achieved the old one is also printed
        scoreOutputString = "highscore:";
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 60);
        window->draw(text);
        scoreOutputString = std::to_string(highscore);
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 100);
        window->draw(text);
        scoreOutputString = "score:";
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 140);
        window->draw(text);
        scoreOutputString = std::to_string(score);
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 180);
        window->draw(text);
        scoreOutputString = "press [R] to restart";
        text.setString(scoreOutputString);
        text.setPosition(350 - text.getLocalBounds().width / 2, 220);
        window->draw(text);
    }
    sprites[0]->setScale(0.9, 0.9); // sets a big version of the character at the bottom of the screen
    sprites[0]->setPosition(177, 280);
    window->draw(*sprites[0]);
    releaseFrame();
}