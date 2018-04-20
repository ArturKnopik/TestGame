
#include "SimpleCreatureController.h"
#include "Entity.h"

SimpleCreatureController::SimpleCreatureController(std::shared_ptr<Positions> cPositions, float cSpeed) :
        Controller(cPositions, cSpeed)
{

    std::cout<<"Create SimpleCreatureController - ";
}

//Controller(std::shared_ptr<Entity> cEntity, const float cSpeed );
SimpleCreatureController::~SimpleCreatureController() {

    std::cout<<"Destroy SimpleCreatureController - ";
}

void SimpleCreatureController::control() {


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

