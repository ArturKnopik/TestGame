//
// Created by Root on 30.03.2018.
//

#include "Entity/Entity.h"

void Entity::setPosition(const sf::Vector2f newPostion) {
    position=newPostion;
}

const sf::Vector2f Entity::getPosition() {
    return position;
}

void Entity::setColsionAble(const bool colisionType) {
    canCollidet=colisionType;
}

const bool Entity::isCollisionAble() {
    return canCollidet;
}

Entity::Entity(int x, int y, bool cCanCollidet, Layers cLayer)
: canCollidet(cCanCollidet), zLayer(cLayer)
{
   position=sf::Vector2f(x,y);
}

Entity::~Entity() {

}

const short Entity::getZLayer() {
    return zLayer;
}
