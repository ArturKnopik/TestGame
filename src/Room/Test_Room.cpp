//
// Created by Root on 04.04.2018.
//

#include <Entity/Brick.h>
#include <Systems/CollisionChecker.h>
#include <ControllComponent/Controller.h>
#include <ControllComponent/SimpleCreatureController.h>
#include <Entity/SimpleEnemy.h>
#include <Entity/Player.h>
#include "Room/Test_Room.h"

Test_Room::Test_Room(float xToSpawnPlayer, float yToSpawnPlayer, std::shared_ptr<sf::Event> cEvent)
        : Room(xToSpawnPlayer, yToSpawnPlayer, cEvent)
{
    loadRoom();
    std::cout << "Create Test_Room - ";
}

void Test_Room::update(const float dt)
{
    colCheck.checkEntityInhArray(getEntityList());

    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->update(dt);
    }
}

void Test_Room::draw(std::shared_ptr<sf::RenderWindow> window)
{

    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::BACKGROUND_LAYER)
        {

            entityList[i]->draw(window);
        }
    }
    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::UNDERPLAYER_LAYER)
        {

            entityList[i]->draw(window);
        }
    }
    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::CREATURES)
        {

            entityList[i]->draw(window);
        }
    }
    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::PARTICLE_LAYER)
        {

            entityList[i]->draw(window);
        }
    }
    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::BEFOREPLAYER_LAYER)
        {

            entityList[i]->draw(window);
        }
    }
    for (int i = 0; i < entityList.size(); i++)
    {
        if (entityList[i]->getZLayer() == Layers::WEATHER_LAYER)
        {

            entityList[i]->draw(window);
        }
    }
}

void Test_Room::loadRoom()
{

    entityList.push_back(std::unique_ptr<Entity>(new Player(100, 100, event, Layers::CREATURES)));
    entityList.push_back(std::unique_ptr<Entity>(new Brick(200, 200, true, Layers::UNDERPLAYER_LAYER)));
    entityList.push_back(std::unique_ptr<Entity>(new Brick(300, 200, false, Layers::UNDERPLAYER_LAYER)));
    entityList.push_back(std::unique_ptr<Entity>(new Brick(320, 200, true, Layers::UNDERPLAYER_LAYER)));
    entityList.push_back(std::unique_ptr<Entity>(new SimpleEnemy(150, 150)));

}

Test_Room::~Test_Room()
{

    std::cout << "Destroy test room" << std::endl;
}
