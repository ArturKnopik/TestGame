//
// Created by Root on 07.04.2018.
//

#ifndef TESTGAME_PHYSICS_H
#define TESTGAME_PHYSICS_H

#include <vector>

enum EntityState
{
    JUMPING,
    FALLING,
    MOVING,
    STOP,
    CROWDCONTROL,
};
class Physics
{
private:
    float acceleration;
    float gravity;
    float speed=0;
    float maxSpeed;
    EntityState entityState=STOP;
    float x;
    float y;
public:
    Physics();
    Physics(const float cAcceleration, const float cMaxSpeed, const float cGravity);
    const float getGravity();
    const float getAcceleration();
   // const std::vector<EntityState > & getEntityState();
    void update(const float dt);
   // void setStartPoint(float X)



};


#endif //TESTGAME_PHYSICS_H
