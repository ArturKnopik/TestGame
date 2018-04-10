//
// Created by Root on 03.04.2018.
//

#ifndef SFML_GAME_ROOMLEVEL_H
#define SFML_GAME_ROOMLEVEL_H

#include <memory>
#include <vector>
#include <Entity/Entity.h>

class Room {
protected:
    std::vector<std::unique_ptr<Entity>> entityList;
    std::shared_ptr<sf::Event> event;
public:
    Room()=delete;
    Room(float xToSpawnPlayer, float yToSpawnPlayer, std::shared_ptr<sf::Event> cEvent);
    virtual void update(const float dt)=0;
    virtual void draw(std::shared_ptr<sf::RenderWindow> window)=0;
    virtual void loadRoom()=0;
    std::vector<std::unique_ptr<Entity>> & getEntityList();
    virtual ~Room();
};


#endif //SFML_GAME_ROOMLEVEL_H
