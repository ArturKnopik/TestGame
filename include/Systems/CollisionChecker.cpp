
#include "CollisionChecker.h"
#include "Entity.h"

CollisionChecker::CollisionChecker() {
    std::cout<<"Create CollisionChecker - ";
}

void CollisionChecker::init() {

}

bool CollisionChecker::checkAABB() {


}

void CollisionChecker::checkEntityInhArray() {

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

