//
// Created by Streaming on 2018-02-08.
//

#ifndef SFML_GAME_SNAKEGAMESTATE_H
#define SFML_GAME_SNAKEGAMESTATE_H


#include "GameState.h"

class SnakeGameState :
        public GameState
{
    float speed;
    int difficult;
   // std::vector<std::vector> map;

public:
    SnakeGameState(std::shared_ptr<Game> game);
    void draw();
    void update(const float dt);
    void input();
};


#endif //SFML_GAME_SNAKEGAMESTATE_H
