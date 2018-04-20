
#include "PlayerController.h"
#include "Entity.h"

PlayerController::PlayerController(std::shared_ptr<Positions> cPositions, const float cSpeed)
        : Controller(cPositions, cSpeed)
{

    std::cout<<"Create PlayerController - ";
}

void PlayerController::setEvent() {

    this->event = event;
}

void PlayerController::control() {


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

PlayerController::~PlayerController() {

    std::cout<<"Destroy PlayerController - ";
}

