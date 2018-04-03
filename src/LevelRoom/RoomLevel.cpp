//
// Created by Root on 03.04.2018.
//

#include "LevelRoom/RoomLevel.h"

void RoomLevel::update(const float dt)
{

}

RoomLevel::RoomLevel(float xToSpawnPlayer, float yToSpawnPlayer)
{

}

std::vector<std::unique_ptr<Entity>> & RoomLevel::getEntityList()
{
    return entityList;
}
