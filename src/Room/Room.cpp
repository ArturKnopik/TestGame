//
// Created by Root on 03.04.2018.
//

#include <Entity/Brick.h>
#include <iostream>
#include "Room/Room.h"

Room::Room(float xToSpawnPlayer, float yToSpawnPlayer, std::shared_ptr<sf::Event> cEvent)
:event(cEvent)
{
}

std::vector<std::unique_ptr<Entity>> & Room::getEntityList()
{
    return entityList;
}

Room::~Room()
{
    std::cout<<"Destroy  Room!"<<std::endl;
}



