//
// Created by Root on 03.04.2018.
//

#include "PlayLevel/PlayedLevel.h"

PlayedLevel::PlayedLevel(const std::string urlToLevel)
{
    // 
}

void PlayedLevel::switchCurrentRoom(int roomToLoad)
{
    roomsVector.push_back(std::move(currentRoom));
    currentRoom=std::move(roomsVector[roomToLoad]);
    roomsVector.erase(roomsVector.begin() + +roomToLoad);
}
