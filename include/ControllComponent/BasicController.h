//
// Created by Root on 30.03.2018.
//

#ifndef SFML_GAME_PLAYERCONTROLLER_H
#define SFML_GAME_PLAYERCONTROLLER_H

#include <SFML/Window/Keyboard.hpp>
#include "Controller.h"

class BasicController : public Controller
{
private:
    std::shared_ptr<sf::Event> event;
public:
	BasicController() = delete;

	BasicController(std::shared_ptr<Positions> cPositions, const float cSpeed);

    void setEvent(std::shared_ptr<sf::Event> event);
    void control(const float dt);
    ~BasicController();


};


#endif //SFML_GAME_PLAYERCONTROLLER_H
