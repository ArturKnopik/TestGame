//
// Created by Root on 30.03.2018.
//



#include "Controll/PlayerController.h"

PlayerController::PlayerController(std::shared_ptr<Entity> cEntity, const float cSpeed)
        : Controller(cEntity, cSpeed)
{

}

void PlayerController::control(const float dt)
{
    std::cout << "X:Y - " << entity->getPosition().x << ":" << entity->getPosition().y << std::endl;
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

void PlayerController::setEvent(std::shared_ptr<sf::Event> event)
{
    this->event = event;
}
