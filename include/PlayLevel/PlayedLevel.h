//
// Created by Root on 03.04.2018.
//

#ifndef SFML_GAME_PLAYLEVEL_H
#define SFML_GAME_PLAYLEVEL_H

#include <string>
#include <LevelRoom/RoomLevel.h>
#include <memory>
#include <vector>

class PlayedLevel
{
    std::unique_ptr<RoomLevel> currentRoom;
    std::vector<std::unique_ptr<RoomLevel>> roomsVector;

public:
    PlayedLevel() = delete;

    PlayedLevel(const std::string urlToLevel);

    virtual void update(const float dt)=0;

    virtual void loadLevel(std::string urlToLevel)=0;

    virtual void saveLevel()=0; // to future use

    void switchCurrentRoom(int roomToLoad);


};


#endif //SFML_GAME_PLAYLEVEL_H
