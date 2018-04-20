#include <Entity\BasicBullet.h>



BasicBullet::BasicBullet(int x, int y, bool cCanCollidet)
	:Entity(x,y, true, Layers::PARTICLE_LAYER)
{

	std::cout << "Create BasicBullet - ";
}

BasicBullet::~BasicBullet()
{
	std::cout << "Destroy BasicBullet - ";
}

void BasicBullet::draw(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(rect);
}

void BasicBullet::update(const float dt)
{
	/*
	switch ()
	{
	case UP:		
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	}
	 */
}

void BasicBullet::whoCanBeTheTarget(Entit_Type hitTarget)
{
	for (int i = 0; i < canHitList.size(); i++)
	{
		if (canHitList[i] == hitTarget)
			return;
	}
	canHitList.push_back(hitTarget);

}
