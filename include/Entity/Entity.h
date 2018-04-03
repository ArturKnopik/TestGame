#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

//
// Created by Root on 30.03.2018.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

enum Layers {
    BACKGROUND_LAYER,
    UNDERPLAYER_LAYER,
    PLAYER_LAYER,
    PARTICLE_LAYER,
    BEFOREPLAYER_LAYER,
    WEATHER_LAYER
};

class Entity {
private:


    bool canCollidet;
    sf::Vector2f position;
    Layers zLayer;

public:
    Entity() = delete;

    Entity(int x, int y, bool cCanCollidet, Layers cZLayer);

    virtual ~Entity();

    virtual void draw(std::shared_ptr<sf::RenderWindow> window)=0;

    virtual void update(const float dt)=0;

    void setPosition(const sf::Vector2f newPostion);

    const sf::Vector2f getPosition();

    const bool isCollisionAble();

    const short getZLayer();


protected:
    void setColsionAble(const bool colisionType);

};


#endif //SFML_GAME_ENTITY_H
