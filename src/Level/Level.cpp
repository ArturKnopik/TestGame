//
// Created by Root on 03.04.2018.
//

#include <iostream>
#include "Level/Level.h"

Level::Level(const std::string urlToLevel, std::shared_ptr<sf::Event> cEvent)
: event(cEvent)
{
     std::cout<<"Create Entity - ";
}

void Level::switchCurrentRoom(int roomToLoad)
{
    roomsVector.push_back(std::move(currentRoom));
    currentRoom=std::move(roomsVector[roomToLoad]);
    roomsVector.erase(roomsVector.begin() + +roomToLoad);
}

Level::~Level()
{
    std::cout<<"Destroy LEVEL"<<std::endl;
}
