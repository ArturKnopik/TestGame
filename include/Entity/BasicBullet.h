#ifndef SFML_GAME_BASIC_BULLET_H
#define SFML_GAME_BASIC_BULLET_H

#include <Entity\Entity.h>
#include<SFML\Graphics\RectangleShape.hpp>
#include "ControllComponent\BasicController.h"

class BasicBullet : public Entity
{
private:
	std::unique_ptr<BasicController> controler;
	sf::RectangleShape rect;
	std::vector<Entit_Type> canHitList;
protected:

public:
	BasicBullet()=delete;
	BasicBullet(int x, int y, bool cCanCollidet); // maby add particle effect etc
	~BasicBullet();
	void draw(std::shared_ptr<sf::RenderWindow> window);
	void update(const float dt);
	void whoCanBeTheTarget(Entit_Type hitTarget);

};

#endif