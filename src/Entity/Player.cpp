//
// Created by Root on 30.03.2018.
//


#include "Entity/Player.h"

Player::Player(int x, int y, std::shared_ptr<sf::Event> & cEvent, Layers cLayer)
        : Entity(x, y, true, cLayer), event(cEvent)
{
    rect.setPosition(getPosition());
    rect.setSize(sf::Vector2f(32, 32));
    playerControler = std::unique_ptr<PlayerController>(new PlayerController(positions, 0.0002));
    std::cout<<"Create Player - ";

}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
    rect.setPosition(getOldPosition());
    window->draw(rect);
}

void Player::update(const float dt)
{
    if(isCollision()==true)
    {
        setPosition(getOldPosition());
    }
    else
    {
        setOldPosition(getPosition());
        playerControler->control(dt);
    }
   // playerControler->control(dt);

}

void Player::input()
{

}

Player::~Player()
{
    std::cout<<"Destroy Player - ";
}
