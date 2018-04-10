//
// Created by Root on 07.04.2018.
//

#include <ControllComponent/SimpleCreatureController.h>
#include "Entity/SimpleEnemy.h"

SimpleEnemy::SimpleEnemy(int x, int y)
:Entity(x, y, true, Layers::CREATURES)
{
    controller=std::unique_ptr<Controller>(new SimpleCreatureController(positions,0.00005));
    rect.setPosition(getPosition());
    rect.setSize(sf::Vector2f(32,32));
    rect.setFillColor(sf::Color::Green);
    std::cout<<"Create Simple_Enemy - ";
}

void SimpleEnemy::draw(std::shared_ptr<sf::RenderWindow> window)
{
    rect.setPosition(getOldPosition());
    window->draw(rect);
}

void SimpleEnemy::update(const float dt)
{
    if(isCollision()==true)
    {
        setPosition(getOldPosition());
    }
    else
    {
        setOldPosition(getPosition());
        controller->control(dt);
    }

}

SimpleEnemy::~SimpleEnemy()
{
    std::cout<<"Destroy SimpleEnemy - ";
}
