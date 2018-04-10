//
// Created by Root on 04.04.2018.
//

#include <Room/Test_Room.h>
#include <ControllComponent/SimpleCreatureController.h>
#include "Level/Test_Level.h"

void Test_Level::saveLevel()
{

}

Test_Level::Test_Level(std::string urlToLevel, std::shared_ptr<sf::Event> cEvent)
        : Level(urlToLevel, event)
{
    currentRoom=std::unique_ptr<Room>(new Test_Room(100,100, event));
}

void Test_Level::update(const float dt)
{
    currentRoom->update(dt);
}

void Test_Level::loadLevel(std::string urlToLevel)
{

}

void Test_Level::draw(std::shared_ptr<sf::RenderWindow> window)
{

    currentRoom->draw(window);
}

Test_Level::~Test_Level()
{
    std::cout<<"Destroy TEST_LEVEL"<<std::endl;
}
