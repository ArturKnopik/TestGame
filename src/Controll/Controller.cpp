//
// Created by Root on 30.03.2018.
//

#include "Controll/Controller.h"

Controller::Controller(std::shared_ptr<Entity> cEntity, float cSpeed)
        : entity(cEntity), speed(cSpeed)
{

}

void Controller::moveUp(const float dt)
{
    entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y - (speed*dt)));
}

void Controller::moveDown(const float dt)
{
    entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y + speed*dt));
}

void Controller::moveLeft(const float dt)
{
    entity->setPosition(sf::Vector2f(entity->getPosition().x - (speed*dt), entity->getPosition().y));
}

void Controller::moveRight(const float dt)
{
    entity->setPosition(sf::Vector2f(entity->getPosition().x + (speed*dt), entity->getPosition().y));
}

void Controller::setSpeed(const float speed)
{
    this->speed = speed;
}

const float Controller::getSpeed()
{
    return speed;
}
