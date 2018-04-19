//
// Created by Streaming on 2017-12-28.
//


#include <Entity/Entity.h>
#include <iostream>
#include "Systems/CollisionChecker.h"

CollisionChecker::CollisionChecker()
{
    std::cout<<"Create CollisionChecker - ";
}

bool CollisionChecker::checkAABB(std::unique_ptr<Entity> &left, std::unique_ptr<Entity> &right)
{

	return true;
}

void CollisionChecker::checkEntityInhArray(std::vector<std::unique_ptr<Entity>> & mapEntity)
{

    for (int i = 0; i < mapEntity.size(); i++)
    {
        for (int j = 0; j < mapEntity.size(); j++)
        {
            if (i != j)
            {
                if (mapEntity[i]->isCollisionAble() && (mapEntity[j]->isCollisionAble()))
                {
                    if (mapEntity[i]->getPosition().x < mapEntity[j]->getPosition().x + mapEntity[j]->getSize().x &&
                            mapEntity[i]->getPosition().x + mapEntity[i]->getSize().x > mapEntity[j]->getPosition().x &&
                            mapEntity[i]->getPosition().y < mapEntity[j]->getPosition().y + mapEntity[j]->getSize().y &&
                            mapEntity[i]->getSize().y + mapEntity[i]->getPosition().y > mapEntity[j]->getPosition().y)
                    {
                        mapEntity[i]->setCollision(true);
                        std::cout<<"collision: "<<i<<":"<<j<<std::endl;
                        break;
                    } else
                    {
                       mapEntity[i]->setCollision(false);
                    }
                }
            }
        }
    }
}


void CollisionChecker::init(std::vector<std::unique_ptr<Entity>> &mapEntity)
{

}


