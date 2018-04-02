//
// Created by Root on 30.03.2018.
//

#ifndef SFML_GAME_CONTROLLER_H
#define SFML_GAME_CONTROLLER_H

#include <iostream>
#include <memory>
#include <Entity/Entity.h>

enum Direction
{
    UP, DOWN, LEFT, RIGHT
};
enum JumpState
{
    JUMP, FALL
};

class Controller
{
private:
    float speed;
protected:
    virtual void moveUp(const float dt);
    virtual void moveDown(const float dt);
    virtual void moveLeft(const float dt);
    virtual void moveRight(const float dt);
    std::shared_ptr<Entity> entity;
public:
    Controller() = delete;

    Controller(std::shared_ptr<Entity> cEntity, const float cSpeed );

    ~Controller() = default;

    virtual void control(const float dt)=0;

    void setSpeed(const float speed);

    const float getSpeed();

};


#endif //SFML_GAME_CONTROLLER_H
