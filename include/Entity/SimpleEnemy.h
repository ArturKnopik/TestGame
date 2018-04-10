//
// Created by Root on 07.04.2018.
//

#ifndef TESTGAME_SIMPLEENEMY_H
#define TESTGAME_SIMPLEENEMY_H


#include <ControllComponent/Controller.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Entity/Entity.h"

class SimpleEnemy
:public Entity
{
private:
    std::unique_ptr<Controller> controller;
    sf::RectangleShape rect;

public:
    SimpleEnemy()= delete;
    SimpleEnemy(int x, int y);
    ~SimpleEnemy();
    void draw(std::shared_ptr<sf::RenderWindow> window);

    void update(const float dt);
};


#endif //TESTGAME_SIMPLEENEMY_H
