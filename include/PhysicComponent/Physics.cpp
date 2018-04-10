//
// Created by Root on 07.04.2018.
//

#include "Physics.h"

Physics::Physics()
{
    acceleration=0,001;
    maxSpeed=0.01;
    gravity=0.005;
    speed=0;
}

Physics::Physics(const float cAcceleration, const float cMaxSpeed, const float cGravity)
:acceleration(cAcceleration), maxSpeed(cMaxSpeed), gravity(cGravity), speed(0)
{

}

const float Physics::getGravity()
{
    return gravity;
}

const float Physics::getAcceleration()
{
    return acceleration;
}
/*
const std::vector<EntityState> &Physics::getEntityState()
{
    return <#initializer#>;
}
*/
void Physics::update(const float dt)
{
    switch(entityState)
    {
        case JUMPING:
            break;
        case FALLING:
            break;
        case MOVING:
            break;
        case CROWDCONTROL:
            break;

    }


}
