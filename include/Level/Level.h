//
// Created by Root on 03.04.2018.
//

#ifndef SFML_GAME_PLAYLEVEL_H
#define SFML_GAME_PLAYLEVEL_H

#include <string>
#include <memory>
#include <vector>
#include <Room/Room.h>

class Level
{
protected:
    std::unique_ptr<Room> currentRoom;
    std::vector<std::unique_ptr<Room>> roomsVector;
    std::shared_ptr<sf::Event> event;

public:
    Level() = default;

    Level(const std::string urlToLevel, std::shared_ptr<sf::Event> cEvent);
    virtual ~Level();
    virtual void update(const float dt)=0;

    virtual void loadLevel(std::string urlToLevel)=0;

    virtual void draw(std::shared_ptr<sf::RenderWindow> window)=0;

    virtual void saveLevel()=0; // to future use

    void switchCurrentRoom(int roomToLoad);


};


#endif //SFML_GAME_PLAYLEVEL_H
