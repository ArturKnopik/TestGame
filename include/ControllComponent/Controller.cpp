
#include "Controller.h"
#include "Entity.h"

void Controller::moveUp() {

    positions->currentPosition.y = positions->currentPosition.y-(speed*dt);
   // entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y - (speed*dt)));
}

void Controller::moveDown() {

    positions->currentPosition.y = positions->currentPosition.y+(speed*dt);
    //entity->setPosition(sf::Vector2f(entity->getPosition().x, entity->getPosition().y + speed*dt));
}

void Controller::moveLeft() {

    positions->currentPosition.x = positions->currentPosition.x-(speed*dt);
   // entity->setPosition(sf::Vector2f(entity->getPosition().x - (speed*dt), entity->getPosition().y));
}

void Controller::moveRight() {

    positions->currentPosition.x = positions->currentPosition.x+(speed*dt);
    //entity->setPosition(sf::Vector2f(entity->getPosition().x + (speed*dt), entity->getPosition().y));
}

Controller::~Controller() {

    std::cout<<"Destroy Controller - ";
}

void Controller::setSpeed() {

    this->speed = speed;
}

float Controller::getSpeed() {

    return speed;
}

