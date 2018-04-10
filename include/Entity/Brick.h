//
// Created by Root on 03.04.2018.
//

#ifndef SFML_GAME_BRICK_H
#define SFML_GAME_BRICK_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Entity.h"

class Brick
        : public Entity {
private:
    sf::RectangleShape rect;
public:
    Brick() = delete;

    Brick(float x, float y, bool cCanCollidet, Layers layer);

    void draw(std::shared_ptr<sf::RenderWindow> window);

    void update(const float dt);
    ~Brick();


};


#endif //SFML_GAME_BRICK_H
