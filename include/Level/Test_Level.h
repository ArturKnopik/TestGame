//
// Created by Root on 04.04.2018.
//

#ifndef SFML_GAME_TEST_LEVEL_H
#define SFML_GAME_TEST_LEVEL_H

#include "Level/Level.h"

class Test_Level : public Level
{
public:
    Test_Level()=delete;
    Test_Level(std::string urlToLevel, std::shared_ptr<sf::Event> cEvent);
    ~Test_Level();
    void update(const float dt);
    void loadLevel(std::string urlToLevel);
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void saveLevel();
};


#endif //SFML_GAME_TEST_LEVEL_H
