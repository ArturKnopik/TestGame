//
// Created by Root on 07.04.2018.
//

#ifndef TESTGAME_SIMPLECREATURECONTROLLER_H
#define TESTGAME_SIMPLECREATURECONTROLLER_H
#include "ControllComponent/Controller.h"

class SimpleCreatureController
: public Controller
{
public:
    SimpleCreatureController(std::shared_ptr<Positions> cPositions, float cSpeed);
    //Controller(std::shared_ptr<Entity> cEntity, const float cSpeed );
    ~SimpleCreatureController();
    void control(const float dt);

protected:

};


#endif //TESTGAME_SIMPLECREATURECONTROLLER_H
