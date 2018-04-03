//
// Created by Root on 03.04.2018.
//

#include "Entity/Brick.h"

Brick::Brick(float x, float y, bool cCanCollidet, Layers cLayer)
        : Entity(x, y, cCanCollidet, cLayer) {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Red);
}

void Brick::draw(std::shared_ptr<sf::RenderWindow> window) {
window->draw(rect);
}

void Brick::update(const float dt) {

}
