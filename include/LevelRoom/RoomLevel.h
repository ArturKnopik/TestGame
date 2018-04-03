//
// Created by Root on 03.04.2018.
//

#ifndef SFML_GAME_ROOMLEVEL_H
#define SFML_GAME_ROOMLEVEL_H

#include <memory>
#include <vector>
#include <Entity/Entity.h>

class RoomLevel {
private:
    std::vector<std::unique_ptr<Entity>> entityList;
public:
    RoomLevel()=delete;
    RoomLevel(float xToSpawnPlayer, float yToSpawnPlayer);
    virtual void update(const float dt)=0;
    virtual void loadRoom()=0;
    std::vector<std::unique_ptr<Entity>> & getEntityList();
};


#endif //SFML_GAME_ROOMLEVEL_H
