//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_PLAYSTATE_H
#define SFML_GAME_PLAYSTATE_H


#include "GameState.h"

class PlayState : public GameState
{
private:
    sf::View viewe;
    std::shared_ptr<sf::Event> event;
public:
    ~PlayState();
    void draw();
    void update(const float dt);
    void input();
    PlayState(std::shared_ptr<Game> game);

};


#endif //SFML_GAME_PLAYSTATE_H
