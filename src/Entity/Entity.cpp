//
// Created by Root on 30.03.2018.
//

#include <iostream>
#include "Entity/Entity.h"

void Entity::setPosition(const sf::Vector2f newPostion)
{
    positions->currentPosition = newPostion;
}

const sf::Vector2f Entity::getPosition()
{
    return positions->currentPosition;
}

void Entity::setColsionAble(const bool colisionType)
{
    canCollidet = colisionType;
}

const bool Entity::isCollisionAble()
{
    return canCollidet;
}

Entity::Entity(int x, int y, bool cCanCollidet, Layers cLayer)
        : canCollidet(cCanCollidet), zLayer(cLayer)
{
    positions=std::shared_ptr<Positions>(new Positions);
    canCollidet = cCanCollidet;
    positions->currentPosition = sf::Vector2f(x, y);
    positions->oldPositions = positions->currentPosition;
    size = sf::Vector2f(32, 32);
}

Entity::~Entity()
{
    std::cout<<"destroy Entity - ";
}

const short Entity::getZLayer()
{
    return zLayer;
}

const sf::Vector2f Entity::getSize()
{
    return size;
}

void Entity::setSize(const sf::Vector2f newSize)
{
    size = newSize;
}

bool Entity::isCollision()
{
    return collision;
}

void Entity::setCollision(const bool col)
{
    collision = col;
}

void Entity::setOldPosition(const sf::Vector2f newPostion)
{
    positions->oldPositions = newPostion;
}

const sf::Vector2f Entity::getOldPosition()
{
    return positions->oldPositions;
}


