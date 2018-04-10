//
// Created by Root on 07.04.2018.
//

#include "ControllComponent/SimpleCreatureController.h"
#include <cstdlib>

void SimpleCreatureController::control(const float dt)
{

    if (rand() < 40000)
    {
        switch (rand() % 5)
        {
            case 1:
                moveUp(dt);
                break;
            case 2:
                moveDown(dt);
                break;
            case 3:
                moveRight(dt);
                break;
            case 4:
                moveLeft(dt);
                break;
        }
    }
}

SimpleCreatureController::~SimpleCreatureController()
{
    std::cout<<"Destroy SimpleCreatureController - ";
}

SimpleCreatureController::SimpleCreatureController(std::shared_ptr<Positions> cPositions, float cSpeed) :
        Controller(cPositions, cSpeed)
{
    std::cout<<"Create SimpleCreatureController - ";
}
