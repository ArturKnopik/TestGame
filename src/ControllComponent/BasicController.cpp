//
// Created by Root on 30.03.2018.
//



#include "ControllComponent/BasicController.h"

BasicController::BasicController(std::shared_ptr<Positions> cPositions, const float cSpeed)
        : Controller(cPositions, cSpeed)
{
    std::cout<<"Create PlayerController - ";
}

void BasicController::control(const float dt)
{

        // std::cout << "X:Y - " << entity->getPosition().x << ":" << entity->getPosition().y << std::endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            moveUp(dt);
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveDown(dt);
            return;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            moveLeft(dt);
            return;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            moveRight(dt);
            return;
        }
}

void BasicController::setEvent(std::shared_ptr<sf::Event> event)
{
    this->event = event;
}

BasicController::~BasicController()
{
    std::cout<<"Destroy PlayerController - ";
}
