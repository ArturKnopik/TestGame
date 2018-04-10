//
// Created by Root on 30.03.2018.
//

#ifndef SFML_GAME_PLAYER_H
#define SFML_GAME_PLAYER_H
// to delate in future
#include <SFML/Graphics/RectangleShape.hpp>
#include <ControllComponent/PlayerController.h>


#include "Entity.h"

class Player : public Entity, std::enable_shared_from_this<Player> {
private:
    sf::RectangleShape rect;
    std::unique_ptr<PlayerController> playerControler;
    std::shared_ptr<sf::Event> event;
public:
    Player(int x, int y, std::shared_ptr<sf::Event> & cEvent, Layers cZLayer); // to add: InputController, MomventClass, drawingStyle
    //player(float x, float y,std::shared_ptr<sf::Event> & cEvent, PhysicComponent physic,  )
    ~Player();

    void draw(std::shared_ptr<sf::RenderWindow> window);

    void update(const float dt);

    void input();

};


#endif //SFML_GAME_PLAYER_H
