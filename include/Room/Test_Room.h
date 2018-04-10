//
// Created by Root on 04.04.2018.
//

#ifndef SFML_GAME_TEST_ROOMLEVEL_H
#define SFML_GAME_TEST_ROOMLEVEL_H


#include "Room.h"
#include "Systems/CollisionChecker.h"

class Test_Room : public Room
{
private:
    CollisionChecker colCheck;
public:
    Test_Room()=delete;
    Test_Room(float xToSpawnPlayer, float yToSpawnPlayer, std::shared_ptr<sf::Event> cEvent);
    void update(const float dt);
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void loadRoom();
    ~Test_Room();
};


#endif //SFML_GAME_TEST_ROOMLEVEL_H
