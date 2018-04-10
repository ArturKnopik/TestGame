#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

//
// Created by Root on 30.03.2018.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

enum Layers {
    BACKGROUND_LAYER=1,
    UNDERPLAYER_LAYER=2,
    CREATURES=3,
    PARTICLE_LAYER=4,
    BEFOREPLAYER_LAYER=5,
    WEATHER_LAYER=6
};
struct Positions
{
    Positions(){};
    sf::Vector2f currentPosition;
    sf::Vector2f oldPositions;
};

class Entity {
private:


    bool canCollidet;
    bool collision;
    sf::Vector2f size;
    Layers zLayer;
protected:
    void setSize(const sf::Vector2f newSize);
    void setColsionAble(const bool colisionType);
    void setOldPosition(const sf::Vector2f newPostion);
    std::shared_ptr<Positions> positions;
    const sf::Vector2f getOldPosition();

public:
    Entity() = delete;

    Entity(int x, int y, bool cCanCollidet, Layers cZLayer);

    virtual ~Entity();

    virtual void draw(std::shared_ptr<sf::RenderWindow> window)=0;

    virtual void update(const float dt)=0;

    bool isCollision();

    void setCollision(const bool col);


    void setPosition(const sf::Vector2f newPostion);

    const sf::Vector2f getPosition();


    const sf::Vector2f getSize();

    const bool isCollisionAble();

    const short getZLayer();



};


#endif //SFML_GAME_ENTITY_H
