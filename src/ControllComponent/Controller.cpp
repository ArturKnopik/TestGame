//
// Created by Root on 30.03.2018.
//

#include "ControllComponent/Controller.h"

Controller::Controller(std::shared_ptr<Positions> cPosytiond, float cSpeed)
        : speed(cSpeed)
{
    positions = cPosytiond;
}

void Controller::moveUp(const float dt)
{
    positions->currentPosition.y = positions->currentPosition.y-(speed*dt);
   // entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y - (speed*dt)));
}

void Controller::moveDown(const float dt)
{
    positions->currentPosition.y = positions->currentPosition.y+(speed*dt);
    //entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y + speed*dt));
}

void Controller::moveLeft(const float dt)
{
    positions->currentPosition.x = positions->currentPosition.x-(speed*dt);
   // entity->setPosition(sf::Vector2f(entity->getPosition().x - (speed*dt), entity->getPosition().y));
}

void Controller::moveRight(const float dt)
{
    positions->currentPosition.x = positions->currentPosition.x+(speed*dt);
    //entity->setPosition(sf::Vector2f(entity->getPosition().x + (speed*dt), entity->getPosition().y));
}

void Controller::setSpeed(const float speed)
{
    this->speed = speed;
}

const float Controller::getSpeed()
{
    return speed;
}

Controller::~Controller()
{
    std::cout<<"Destroy Controller - ";
}

