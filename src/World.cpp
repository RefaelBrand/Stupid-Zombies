#include "World.h"

using Utils::WIN_H;
using Utils::WIN_W;
using Utils::FRAMERATE_LINIT;

const b2Vec2 gravity = b2Vec2(0, -10);



World::World(sf::RenderWindow& window)
	:m_window(window), m_b2world(make_shared<b2World>(gravity)), m_cannon({ 50, -50 }, 10)
{
	//set the collision listenner and handler 
	m_b2world->SetContactListener(&m_collisionHandler); 
}

void World::createZombie(sf::Vector2f position, float rotation)
{
	m_zombies.push_back(make_unique<Zombie>(m_b2world, position, rotation));
}

void World::createBullet(const sf::Vector2f& pos, const b2Vec2& force)
{
	m_shapes.push_back(make_unique<Bullet>(m_b2world, pos, force));
}

void World::draw()
{
	m_b2world->Step((1.f / FRAMERATE_LINIT), 6, 3);

	update();
	//m_window.clear();

	for (const auto& obj : m_shapes)
	{
		obj->update();
		obj->draw(m_window);
	}

	for (const auto& obj : m_zombies)
	{
		obj->update();
		obj->draw(m_window);
	}

	m_cannon.draw(m_window);
}

void World::update()
{
	std::erase_if(m_shapes, [](const unique_ptr<GameObj>& obj)->bool{ return obj->isErased(); });
	std::erase_if(m_zombies, [](const unique_ptr<Zombie>& obj)->bool{ return obj->isErased(); });
}

void World::clear()
{
	m_shapes.clear();
	m_zombies.clear();
}

void World::handleMouseMoved(sf::Vector2f pos)
{
	m_cannon.handleMouseMoved(pos);
}

void World::handleMouseReleased(sf::Vector2f point)
{
	m_cannon.handleMouseReleased(*this, point);
}

void World::setBulletsCount(unsigned count)
{
	m_cannon.setBulletsCount(count);
}

bool World::isLoss() const
{
	return !(m_cannon.areBulletsLeft());
}

bool World::isWin() const
{
	return m_zombies.size() == 0; // if there are no zombies left
}
