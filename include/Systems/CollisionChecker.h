//
// Created by Streaming on 2017-12-28.
//

#ifndef SFML_GAME_COLLISIONCHECKER_H
#define SFML_GAME_COLLISIONCHECKER_H

#include <memory>
#include <vector>


class CollisionChecker
{

public:
    CollisionChecker();

    void init(std::vector<std::unique_ptr<Entity>> &mapEntity);

    bool checkAABB(std::unique_ptr<Entity> &left, std::unique_ptr<Entity> &right);

    void checkEntityInhArray(std::vector<std::unique_ptr<Entity>>&  mapEntity);

};


#endif //SFML_GAME_COLLISIONCHECKER_H
